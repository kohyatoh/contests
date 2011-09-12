#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

typedef bool result;
result parse(string ex);
char nextToken();
result expr_or();
result expr_and();
result term();

string _s;
unsigned _ix;
char token;

result parse(string ex) {
    _s = ex;
    _ix = 0;
    token = nextToken();
    return expr_or();
}

char nextToken() {
    if(_ix==_s.size()) return 0;
    while(_ix<_s.size() && _s[_ix]==' ') _ix++;
    return _s[_ix++];
}

result expr_or() {
    result r(expr_and());
    while(token=='|') {
        token = nextToken();
        result v(expr_and());
        r |= v;
    }
    return r;
}

result expr_and() {
    result r(term());
    while(token=='&') {
        token = nextToken();
        result v(term());
        r &= v;
    }
    return r;
}

result term() {
    if(token=='!') {
        token = nextToken();
        return !term();
    }
    else if(token=='(') {
        token = nextToken();
        result r(expr_or());
        // token==')'
        token = nextToken();
        return r;
    }
    result r(token=='V');
    token = nextToken();
    return r;
}

int main() {
    string s;
    for(int t=0; getline(cin, s); t++) {
        cout << "Expression " << t+1 << ": " << (parse(s)?'V':'F') << endl;
    }
    return 0;
}

