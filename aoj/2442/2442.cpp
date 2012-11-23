#include <stdio.h>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef complex<double> P;
#define EPS (1e-9)

inline double dot(const P& a, const P& b) { return real(conj(a)*b); }
inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    if (abs(A) < EPS && abs(B) < EPS) return m0;
    return m0 + B/A*(m1-m0);
}

bool ok(const vector<P>& ps) {
    const int m = ps.size();
    if (m%2) return false;
    rep (i, m/2) {
        if (fabs(cross(ps[i+1]-ps[i], ps[(m/2+i+1)%m]-ps[m/2+i])) > EPS) {
            return false;
        }
    }
    const P cp = crosspoint(ps[0], ps[m/2], ps[1], ps[m/2+1]);
    rep (i, m/2) if (i) {
        const P p = crosspoint(ps[0], ps[m/2], ps[i], ps[m/2+i]);
        if (abs(p-cp) > EPS) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<P> ps;
    rep (i, n) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        ps.push_back(P(x, y));
    }
    if (ok(ps)) {
        const int m = ps.size();
        const P cp = crosspoint(ps[0], ps[m/2], ps[1], ps[m/2+1]);
        printf("%.12f %.12f\n", cp.real(), cp.imag());
    }
    else {
        puts("NA");
    }
    return 0;
}
