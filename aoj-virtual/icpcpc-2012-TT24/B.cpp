#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <complex>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;
#define inf (1e100)
#define EPS (1e-9)

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }
inline P projection(const P& l0, const P& l1, const P& p) {
    return l0 + dot(p-l0, l1-l0) / norm(l1-l0) * (l1-l0);
}

int n;
P ps[128];

double solve() {
    double ans = inf;
    rep (a, n) rep (b, n) if (a != b) {
        double mx = 0;
        rep (i, n) if (i != a && i != b) {
            if (cross(ps[i]-ps[a], ps[b]-ps[a]) > EPS) mx = inf;
            mx = max(mx, abs(projection(ps[a], ps[b], ps[i])-ps[i]));
            if (mx >= ans) break;
        }
        ans = min(ans, mx);
    }
    return ans;
}

int main() {
    for (int _q = 0;; _q++) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            ps[i] = P(x, y);
        }
        const double ans = ceil(solve() * 100) / 100;
        printf("Case %d: %.2f\n", _q+1, ans);
    }
}
