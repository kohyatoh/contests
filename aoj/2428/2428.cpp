#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

const char cs[] = "01+-*()";
char src[128], s[128];
int _i, token;

void check(int a) {
    if (a < 0 || a >= 1024) throw "overflow";
}

int next() {
    if (s[_i] == 0) return 0;
    if (s[_i] == '0' || s[_i] == '1') {
        int a = 0;
        while (s[_i] == '0' || s[_i] == '1') {
            a = a * 2 + (s[_i++]-'0');
            check(a);
        }
        return -(a+1);
    }
    return s[_i++];
}

pair<int, bool> expr(), term(), factor();

int parse() {
    _i = 0;
    token = next();
    const int ans = expr().first;
    if (token != 0) throw "ill end";
    return ans;
}

pair<int, bool> expr() {
    pair<int, bool> a = term();
    while (token == '+' || token == '-') {
        const char op = token;
        token = next();
        const pair<int, bool> b = term();
        a.first = op == '+' ? a.first + b.first : a.first - b.first;
        a.second = true;
        check(a.first);
    }
    return a;
}

pair<int, bool> term() {
    pair<int, bool> a = factor();
    while (token == '*') {
        token = next();
        const pair<int, bool> b = factor();
        a.first = a.first * b.first;
        a.second = true;
        check(a.first);
    }
    return a;
}

pair<int, bool> factor() {
    if (token < 0) {
        const int a = -(token+1);
        token = next();
        return mp(a, false);
    }
    if (token == '(') {
        token = next();
        pair<int, bool> a = expr();
        if (a.second == false) throw "(-)";
        if (token != ')') throw "unmatched";
        token = next();
        return mp(a.first, false);
    }
    throw "ill char";
}

int main() {
    scanf("%s", src);
    int ans = -1;
    rep (b, 7*7*7*7*7) {
        for (int i = 0, p = b; src[i]; i++) {
            s[i] = src[i];
            if (s[i] == '.') {
                s[i] = cs[p%7];
                p /= 7;
            }
        }
        try {
            ans = max(ans, parse());
        }
        catch (const char *err) {
            //printf("%s\n", err);
        }
    }
    printf("%d\n", ans);
    return 0;
}
