#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

string token, _s;
unsigned _ix;
void next() {
    if(_ix>=_s.size()) token = "";
    else {
        unsigned k = _ix;
        if(!isdigit(_s[_ix])) _ix++;
        else while(_ix<_s.size() && isdigit(_s[_ix])) _ix++;
        token = _s.substr(k, _ix-k);
    }
}

unsigned myatoi(const string& s) {
    unsigned a = 0;
    rep(i, s.size()) a = a*10+s[i]-'0';
    return a;
}


typedef vector<vector<unsigned> > mat;
inline int rsize(const mat& a) {
    return a.size();
}
inline int csize(const mat& a) {
    assert(rsize(a)>0);
    return a[0].size();
}
mat mul(const mat& a, const mat& b) {
    if(csize(a)==1 && rsize(a)==1) {
        mat r(rsize(b), vector<unsigned>(csize(b)));
        rep(i, rsize(r)) rep(j, csize(r)) r[i][j] = a[0][0]*b[i][j];
        return r;
    }
    else if(csize(b)==1 && rsize(b)==1) return mul(b, a);
    else {
        assert(csize(a)==rsize(b));
        mat r(rsize(a), vector<unsigned>(csize(b)));
        rep(i, rsize(a)) rep(j, csize(b)) rep(k, csize(a)) {
            r[i][j]+=a[i][k]*b[k][j];
        }
        return r;
    }
}
void print(const mat& a) {
    rep(i, rsize(a)) rep(j, csize(a)) {
        printf("%d%c", a[i][j]%(1<<15), j<csize(a)-1 ? ' ' : '\n');
    }
}


map<char, mat> vars;
mat expr(), term(), factor(), primary(), row();

mat parse(const string& src) {
    _s = src;
    _ix = 0;
    next();
    return expr();
}
mat expr() {
    mat r(term());
    while(token=="+" || token=="-") {
        char op = token[0];
        next();
        mat t(term());
        assert(rsize(r)==rsize(t));
        assert(csize(r)==csize(t));
        if(op=='+') rep(i, rsize(r)) rep(j, csize(r)) r[i][j] += t[i][j];
        if(op=='-') rep(i, rsize(r)) rep(j, csize(r)) r[i][j] -= t[i][j];
    }
    return r;
}
mat term() {
    mat r(factor());
    while(token=="*") {
        next();
        r = mul(r, factor());
    }
    return r;
}
mat factor() {
    if(token!="-") return primary();
    else {
        next();
        mat r(factor());
        rep(i, rsize(r)) rep(j, csize(r)) r[i][j] = -r[i][j];
        return r;
    }
}
mat primary() {
    mat r;
    if(isdigit(token[0])) r = mat(1, vector<unsigned>(1, myatoi(token)));
    else if(isupper(token[0])) r = vars[token[0]];
    else if(token[0]=='(') {
        next();
        r = expr();
        assert(token==")");
    }
    else {
        assert(token=="[");
        next();
        r = row();
        while(token==";") {
            next();
            mat t(row());
            assert(csize(r)==csize(t));
            rep(i, rsize(t)) r.push_back(t[i]);
        }
        assert(token=="]");
    }
    next();
    while(token=="'" || token=="(") {
        if(token=="'") {
            next();
            mat t(csize(r), vector<unsigned>(rsize(r)));
            rep(i, rsize(r)) rep(j, csize(r)) t[j][i] = r[i][j];
            r = t;
        }
        else if(token=="(") {
            next();
            mat ix(expr());
            assert(token==",");
            next();
            mat jx(expr());
            assert(token==")");
            next();
            mat t(csize(ix), vector<unsigned>(csize(jx)));
            rep(i, csize(ix)) rep(j, csize(jx)) {
                t[i][j] = r[ix[0][i]-1][jx[0][j]-1];
            }
            r = t;
        }
    }
    return r;
}
mat row() {
    mat r(expr());
    while(token==" ") {
        next();
        mat t(expr());
        assert(rsize(r)==rsize(t));
        rep(i, rsize(r)) rep(j, csize(t)) r[i].push_back(t[i][j]);
    }
    return r;

}

int main() {
    for(;;) {
        string s;
        getline(cin, s);
        const int n = myatoi(s);
        if(n==0) return 0;
        vars.clear();
        rep(i, n) {
            getline(cin, s);
            const char var = s[0];
            mat r(parse(s.substr(2)));
            print(r);
            vars[var] = r;
        }
        puts("-----");
    }
    return 0;
}

