#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

template<class T>
vector<T> make_union(const vector<T>& a, const vector<T>& b) {
    vector<T> r(a.size()+b.size());
    r.resize(set_union(a.begin(), a.end(), b.begin(), b.end(), r.begin())-r.begin());
    return r;
}
template<class T>
vector<T> make_diff(const vector<T>& a, const vector<T>& b) {
    vector<T> r(a.size());
    r.resize(set_difference(a.begin(), a.end(), b.begin(), b.end(), r.begin())-r.begin());
    return r;
}
template<class T>
vector<T> make_intersection(const vector<T>& a, const vector<T>& b) {
    vector<T> r(a.size());
    r.resize(set_intersection(a.begin(), a.end(), b.begin(), b.end(), r.begin())-r.begin());
    return r;
}

typedef vector<char> result;
result parse(string ex);
char nextToken();
result expr();
result term();
result elem();

string _s;
unsigned _ix;
char token;

result parse(string ex) {
    _s = ex;
    _ix = 0;
    token = nextToken();
    return expr();
}

char nextToken() {
    if(_ix==_s.size()) return 0;
    while(_ix<_s.size() && _s[_ix]==' ') _ix++;
    return _s[_ix++];
}

result expr() {
    result r(term());
    while(token=='+' || token=='-') {
        char op=token;
        token = nextToken();
        result v(term());
        if(op=='+') r=make_union(r, v);
        else r=make_diff(r, v);
    }
    return r;
}

result term() {
    result r(elem());
    while(token=='*') {
        token = nextToken();
        result v(elem());
        r = make_intersection(r, v);
    }
    return r;
}

result elem() {
    if(token=='(') {
        token = nextToken();
        result r(expr());
        // token==')'
        token = nextToken();
        return r;
    }
    else {
        // token=='{'
        token = nextToken();
        result r;
        while(token!='}') {
            r.push_back(token);
            token = nextToken();
        }
        sort(r.begin(), r.end());
        token = nextToken();
        return r;
    }
}

int main() {
    string s;
    while(cin>>s) {
        vector<char> r(parse(s));
        putchar('{');
        rep(i, r.size()) putchar(r[i]);
        printf("}\n");
    }
    return 0;
}

