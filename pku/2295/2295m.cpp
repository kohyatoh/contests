#include <stdio.h>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

typedef pair<int, int> result;
result parse(string ex);
string nextToken();
result expr();
result elem();

string _s;
unsigned _ix;
string token;

result parse(string ex) {
    _s = ex;
    _ix = 0;
    token = nextToken();
    return expr();
}

string nextToken() {
    if(_ix==_s.size()) return "";
    unsigned k=1;
    if('0'<=_s[_ix] && _s[_ix]<='9') {
        while(_ix+k<_s.size() && '0'<=_s[_ix+k] && _s[_ix+k]<='9') k++;
    }
    _ix += k;
    return _s.substr(_ix-k, k);
}

result expr() {
    result r(elem());
    while(token=="+" || token=="-") {
        int f=token=="+"?1:-1;
        token = nextToken();
        result v(elem());
        r.first += f*v.first;
        r.second += f*v.second;
    }
    return r;
}

result elem() {
    int a, f=1;
    if(token=="-") {
        f = -1;
        token = nextToken();
    }
    if(token=="x") a=1;
    else {
        a=atoi(token.c_str());
        token = nextToken();
    }
    if(token!="x") return mp(0, f*a);
    else {
        token = nextToken();
        return mp(f*a, 0);
    }
}

int main() {
    string s;
    getline(cin, s);
    int T=atoi(s.c_str());
    while(T--) {
        getline(cin, s);
        int ix=s.find('=');
        pair<int, int> l(parse(s.substr(0, ix))), r(parse(s.substr(ix+1)));
        int x1=l.first-r.first, x0=l.second-r.second;
        if(x1==0) puts(x0 ? "IMPOSSIBLE" : "IDENTITY");
        else {
            int a=abs(x0), b=abs(x1);
            if(-x0*x1>=0) printf("%d\n", a/b);
            else printf("-%d\n", a/b+(a%b>0));
        }
    }
    return 0;
}

