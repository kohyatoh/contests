#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<char, int> ids;
char names[16];
int f0[16], f1[16];

int call(int ix, int p, int x) {
    if (p == 0) return x;
    if (p >= 3) return call(ix, 2-p%2, x);
    int a = 0;
    rep (i, 31) {
        if (x&(1<<i)) a |= f1[ix]&(1<<i);
        else a |= f0[ix]&(1<<i);
    }
    return p == 1 ? a : call(ix, p-1, a);
}

char _s[1024];
int _ix;

char token() {
    return _s[_ix];
}

int number() {
    int a = 0;
    while (isdigit(_s[_ix])) {
        a = a*10 + (_s[_ix]-'0');
        _ix++;
    }
    return a;
}

int expr(int x);

int parse(int x) {
    _ix = 5;
    return expr(x);
}

int expr(int x) {
    if (token() == 'x') {
        _ix++;
        return x;
    }
    else if (token() == '(') {
        _ix++;
        const int a = expr(x);
        const char op = token();
        _ix++;
        const int b = expr(x);
        assert(token() == ')');
        _ix++;
        if (op == '|') return a | b;
        else if (op == '^') return a ^ b;
        else if (op == '&') return a & b;
        assert(false);
        return -1;
    }
    else if (isdigit(token())) {
        return number();
    }
    else {
        assert(ids.count(token()));
        const int id = ids[token()];
        _ix++;
        int p = 1;
        if (token() == '^') {
            _ix++;
            p = number();
        }
        assert(token() == '(');
        _ix++;
        const int y = expr(x);
        assert(token() == ')');
        _ix++;
        return call(id, p, y);
    }
}

int main() {
    fgets(_s, 1024, stdin);
    const int N = atoi(_s);
    rep (i, N) {
        fgets(_s, 1024, stdin);
        names[i] = _s[0];
        ids[_s[0]] = i;
        f0[i] = parse(0);
        f1[i] = parse(0xffffffff);
    }
    rep (i, N) {
        printf("%c(x)=", names[i]);
        int a = 0, b = 0, c = 0;
        rep (j, 31) {
            const int x = 1<<j;
            if ((f0[i]&x) && (f1[i]&x)) a |= x;
            if (!(f0[i]&x) && (f1[i]&x)) b |= x;
            if ((f0[i]&x) && !(f1[i]&x)) c |= x;
        }
        printf("(%d|((x^%d)&%d))\n", a, c, b|c);
    }
    return 0;
}
