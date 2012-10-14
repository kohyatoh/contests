#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
#define EPS (1e-10)

double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b -= a; c -= a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
    if(dot(b, c)<0) return 2;
    if(norm(b)<norm(c)) return -2;
    return 0;
}
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double a = cross(l1-l0, m1-m0);
    const double b = cross(l1-l0, l1-m0);
    if(abs(a)<EPS && abs(b)<EPS) return m0;
    return m0 + b/a*(m1-m0);
}
double polygon_size(const vector<P>& v) {
    double s = 0;
    rep(i, v.size()-2) s += cross(v[i+1]-v[0], v[i+2]-v[0]);
    return fabs(s)/2;
}
vector<P> convex_cut(const vector<P>& v, const P& l0, const P& l1) {
    vector<P> r;
    rep(i, v.size()) {
        const P &a(v[i]), &b(v[(i+1)%v.size()]);
        if(ccw(l0, l1, a)!=-1) r.push_back(a);
        if(ccw(l0, l1, a)*ccw(l0, l1, b)<0) {
            r.push_back(crosspoint(l0, l1, a, b));
        }
    }
    return r;
}

double size(const vector<P>& ps, const P& p) {
    return polygon_size(convex_cut(ps, p, P(0, 0)));
}

P solve(const vector<P>& ps) {
    const double H = polygon_size(ps) / 2;
    rep (i, ps.size()) {
        P a = ps[i], b = ps[(i+1)%ps.size()];
        if (size(ps, a) > size(ps, b)) swap(a, b);
        if (size(ps, a)-EPS <= H && H <= size(ps, b)+EPS) {
            double l = 0, r = 1;
            rep (_, 100) {
                const double mid = (l+r) / 2;
                if (size(ps, a+mid*(b-a)) < H) l = mid; else r = mid;
            }
            return a+l*(b-a);
        }
    }
    assert(false);
    return P(0, 0);
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        vector<P> ps;
        rep(i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            ps.push_back(P(x, y));
        }
        const P p = solve(ps);
        printf("%.15f %.15f\n", p.real(), p.imag());
    }
}
