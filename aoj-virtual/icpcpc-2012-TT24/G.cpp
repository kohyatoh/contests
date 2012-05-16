#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

string _s;
unsigned _ix;
int token;

void next() {
    while (_ix < _s.size() && isspace(_s[_ix])) _ix++;
    if (_ix == _s.size()) {
        token = 0;
        return ;
    }
    if (!isdigit(_s[_ix])) {
        token = _s[_ix++];
    }
    else {
        int a = 0;
        while (isdigit(_s[_ix])) a = a*10+(_s[_ix++]-'0');
        token = -a-1;
    }
}

typedef vector<int> T;
typedef vector<pair<int, T> > E;

void dump(const E& e) {
    printf("E = ");
    rep (k, e.size()) {
        if (k) printf("+");
        printf("(%d)", e[k].first);
        rep (i, 26) if (e[k].second[i]) {
            printf("%c^%d", i+'a', e[k].second[i]);
        }
    }
    printf("\n");
}

E norm(const E& e) {
    map<T, int> f;
    rep (i, e.size()) f[e[i].second] += e[i].first;
    E n;
    for (map<T, int>::iterator it = f.begin(); it != f.end(); ++it) {
        if (it->second) n.push_back(mp(it->second, it->first));
    }
    return n;
}

T mul(T l, const T& r) {
    rep (i, 26) l[i] += r[i];
    return l;
}

E mul(const E& l, const E& r) {
    E e;
    rep (i, l.size()) rep (j, r.size()) {
        e.push_back(mp(l[i].first*r[j].first, mul(l[i].second, r[j].second)));
    }
    return e;
}

E expr(), term(), factor();

E expr() {
//    printf("expr token = %d\n", token);
    E a = term();
    while (token == '+' || token == '-') {
        const bool neg = token == '-';
        next();
        E b = term();
        if (neg) rep (i, b.size()) b[i].first *= -1;
        rep (i, b.size()) a.push_back(b[i]);
    }
    return norm(a);
}

E term() {
//    printf("term token = %d\n", token);
    E a = factor();
    while (token < 0 || isalpha(token) || token == '(') {
        E b = factor();
        a = mul(a, b);
    }
    return a;
}

E factor() {
//    printf("factor token = %d\n", token);
    if (token < 0) {
        const int a = -token-1;
        next();
        E e;
        e.push_back(mp(a, T(26, 0)));
        return e;
    }
    else if (isalpha(token)) {
        const int a = token-'a';
        int x = 1;
        next();
        if (token == '^') {
            next();
            bool neg = false;
            if (token == '-') {
                neg = true;
                next();
            }
            x = -token-1;
            if (neg) x = -x;
            next();
        }
        T t(26, 0);
        t[a] = x;
        E e;
        e.push_back(mp(1, t));
        return e;
    }
    else {
        assert(token == '(');
        next();
        E e = expr();
        assert(token == ')');
        next();
        return e;
    }
}

E parse(string s) {
    _s = s;
    _ix = 0;
    next();
    return expr();
}

int main() {
    string s;
    for (;;) {
        getline(cin, s);
        if (s[0] == '.') return 0;
        E my = parse(s);
//        dump(my);
        for (;;) {
            getline(cin, s);
            if (s[0] == '.') break;
            E your = parse(s);
//            dump(your);
            puts(my == your ? "yes" : "no");
        }
        puts(".");
    }
}
