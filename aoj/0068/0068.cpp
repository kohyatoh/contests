#include <stdio.h>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    }
}
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b -= a, c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}

vector<P> convex_hull(vector<P> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<P> v(2*n);
    for (int i = 0; i < n; v[k++] = ps[i++]) {
        while (k > 1 && ccw(v[k-2], v[k-1], ps[i]) <= 0) k--;
    }
    for (int i = n-2, t = k; i >= 0; v[k++] = ps[i--]) {
        while (k > t && ccw(v[k-2], v[k-1], ps[i]) <= 0) k--;
    }
    v.resize(k-1);
    return v;
}

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        vector<P> ps;
        rep (i, n) {
            double x, y;
            scanf("%lf,%lf", &x, &y);
            ps.push_back(P(x, y));
        }
        vector<P> qs = convex_hull(ps);
        printf("%d\n", (int)(ps.size()-qs.size()));
    }
}
