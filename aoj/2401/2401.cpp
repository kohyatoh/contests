#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string _s;
unsigned _ix;

char token() { return _ix < _s.size() ? _s[_ix] : 0; }
void next() { _ix++; }

int vars;

bool expr() {
    if (token() == 'T') { next(); return true; }
    if (token() == 'F') { next(); return false; }
    if (islower(token())) {
        const int ix =  token() - 'a';
        next();
        return vars & (1<<ix);
    }
    if (token() == '-') {
        next();
        return !expr();
    }
    assert(token() == '(');
    next();
    const bool a = expr();
    int op = -1;
    if (token() == '*') op = 0;
    if (token() == '+') op = 1;
    if (token() == '-') op = 2, next();
    next();
    const bool b = expr();
    assert(token() == ')');
    next();
    if (op == 0) return a&b;
    if (op == 1) return a|b;
    if (op == 2) return (!a)|b;
    assert(false);
    return false;
}

bool parse(const string& s) {
    _s = s;
    _ix = 0;
    return expr();
}

int main() {
    for (;;) {
        string src;
        getline(cin, src);
        if (src == "#") return 0;
        const int pos = src.find('=');
        const string left = src.substr(0, pos), right = src.substr(pos+1);
        bool ans = true;
        rep (b, 1<<11) {
            vars = b;
            if (parse(left) != parse(right)) { ans = false; break; }
        }
        puts(ans ? "YES" : "NO");
    }
}
