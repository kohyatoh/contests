#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

inline Int mabs(Int a) { return a >= 0 ? a : -a; }
Int gcd(Int a, Int b) { return b == 0 ? a : gcd(b, a%b); }

// a / b
struct frac {
    Int a, b;
    frac() : a(0), b(1) {}
    frac(Int _a, Int _b) : a(_a), b(_b) {
        if (b < 0) a *= -1, b *= -1;
        const Int g = gcd(mabs(a), mabs(b));
        a /= g; b /= g;
    }
};

frac operator+(const frac& x, const frac& y) {
    return frac(x.a*y.b+x.b*y.a, x.b*y.b);
}

frac operator-(const frac& x, const frac& y) {
    return frac(x.a*y.b-x.b*y.a, x.b*y.b);
}

frac operator*(const frac& x, const frac& y) {
    return frac(x.a*y.a, x.b*y.b);
}

frac operator/(const frac& x, const frac& y) {
    return frac(x.a*y.b, x.b*y.a);
}

void println(const vector<frac>& a) {
    const int n = a.size();
    bool any = false;
    for (int i = n-1; i >= 0; i--) if (a[i].a) {
        if (any && a[i].a > 0) cout << '+';
        any = true;
        if (i > 0 && mabs(a[i].a) == 1) {
            if (a[i].a < 0) cout << '-';
        }
        else {
            cout << a[i].a;
        }
        if (a[i].b != 1) cout << '/' << a[i].b;
        if (i >= 1) {
            cout << 'x';
            if (i > 1) cout << '^' << i;
        }
    }
    if (!any) printf("%d", 0);
    printf("\n");
}

vector<frac> add(const vector<frac>& a, const vector<frac>& b) {
    const int n = max(a.size(), b.size());
    vector<frac> r(n);
    rep (i, max(a.size(), b.size())) {
        if (i < (int)a.size()) r[i] = r[i] + a[i];
        if (i < (int)b.size()) r[i] = r[i] + b[i];
    }
    return r;
}

vector<frac> mul(const vector<frac>& a, const vector<frac>& b) {
    vector<frac> r(a.size()+b.size()-1);
    rep (i, a.size()) rep (j, b.size()) {
        r[i+j] = r[i+j] + a[i]*b[j];
    }
    return r;
}

vector<frac> mod(vector<frac> a, const vector<frac>& b) {
    while (a.size() >= b.size()) {
        if (b.size() == 1) {
            return vector<frac>(1);
        }
        const int n = a.size();
        const int m = b.size();
        frac f = a[n-1] / b[m-1];
        rep (i, m) a[n-m+i] = a[n-m+i] - f * b[i];
        while (a.size() > 1 && a.back().a == 0) a.pop_back();
    }
    return a;

}

vector<frac> gcd(vector<frac> a, vector<frac> b) {
    if (b.size() == 1 && b[0].a == 0) return a;
    return gcd(b, mod(a, b));
}

string _s;
unsigned ix;

int number();
vector<frac> primary(), factor(), term(), expr();

int number() {
    assert(isdigit(_s[ix]));
    int n = 0;
    while (ix < _s.size() && isdigit(_s[ix])) {
        n = n*10 + (_s[ix]-'0');
        ix++;
    }
    return n;
}

vector<frac> expr() {
    bool minus = false;
    if (_s[ix] == '-') {
        ix++;
        minus = true;
    }
    vector<frac> a(term());
    if (minus) rep (i, a.size()) a[i].a *= -1;
    while (ix < _s.size() && (_s[ix] == '+' || _s[ix] == '-')) {
        const char op = _s[ix++];
        vector<frac> b(term());
        if (op == '-') rep (i, b.size()) b[i].a *= -1;
        a = add(a, b);
    }
    return a;
}

vector<frac> term() {
    vector<frac> a(factor());
    while (ix < _s.size() &&
            (_s[ix] != '+' && _s[ix] != '-' && _s[ix] != ')')) {
        vector<frac> b(factor());
        a = mul(a, b);
    }
    return a;
}

vector<frac> factor() {
    vector<frac> a(primary());
    if (ix < _s.size() && _s[ix] == '^') {
        ix++;
        const int n = number();
        vector<frac> b;
        b.push_back(frac(1, 1));
        rep (_, n) {
            b = mul(b, a);
        }
        return b;
    }
    return a;
}

vector<frac> primary() {
    if (_s[ix] == 'x') {
        ix++;
        vector<frac> a;
        a.push_back(frac(0, 1));
        a.push_back(frac(1, 1));
        return a;
    }
    else if (_s[ix] == '(') {
        ix++;
        vector<frac> a(expr());
        assert(_s[ix] == ')');
        ix++;
        return a;
    }
    else {
        const int n = number();
        vector<frac> a;
        a.push_back(frac(n, 1));
        return a;
    }
}

int main() {
    for (;;) {
        cin >> _s;
        if (_s[0] == '.') return 0;
        ix = 0;
        vector<frac> a(expr());
//        println(a);
        cin >> _s;
        ix = 0;
        vector<frac> b(expr());
//        println(b);
        vector<frac> g(gcd(a, b));
        Int ba = 1;
        rep (i, g.size()) ba *= mabs(g[i].b);
        rep (i, g.size()) g[i] = g[i] * frac(ba, 1);
        Int t = mabs(g[0].a);
        rep (i, g.size()) t = gcd(t, mabs(g[i].a));
        rep (i, g.size()) g[i] = g[i] / frac(t, 1);
        if (g.back().a < 0) rep (i, g.size()) g[i].a *= -1;
        println(g);
    }
}
