#include <stdio.h>
#include <complex>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
#define INF (1e100)
#define EPS (1e-12)

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }
inline P projection(const P& l0, const P& l1, const P& p) {
    const double t = dot(p-l0, l1-l0) / norm(l1-l0);
    return l0 + t*(l1-l0);
}
inline P reflection(const P& l0, const P& l1, const P& p) {
    return 2.0*projection(l0, l1, p) - p;
}
int ccw(const P& a, P b, P c) {
    b -= a; c -= a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
    if(dot(b, c)<0) return 2;
    if(norm(b)<norm(c)) return -2;
    return 0;
}
inline bool intersectSP(const P& s0, const P& s1, const P& p) {
    return abs(s0-p)+abs(s1-p)-abs(s1-s0)<EPS;
}
inline bool intersectSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    return ccw(s0, s1, t0)*ccw(s0, s1, t1) <= 0
        && ccw(t0, t1, s0)*ccw(t0, t1, s1) <= 0;
}
inline P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    if(abs(A)<EPS && abs(B)<EPS) return m0;
//    if(abs(A)<EPS) throw 0;
    return m0 + B/A * (m1-m0);
}

int n, ord[8];
P ps[8][8], qs[8][8], gl[8], st;

bool crossing_any(int d, P s, P t) {
    rep(i, n) {
        if(intersectSP(ps[d][i], qs[d][i], s)) continue;
        if(intersectSP(ps[d][i], qs[d][i], t)) continue;
        if(intersectSS(ps[d][i], qs[d][i], s, t)) return true;
    }
    return false;
}

double calc(int d) {
    P p = st;
    rep(i, d) {
        const int k = ord[i];
        if(!intersectSS(ps[i][k], qs[i][k], p, gl[d])) return INF;
        const P np = crosspoint(ps[i][k], qs[i][k], p, gl[d]);
        if(crossing_any(i, p, np)) return INF;
        p = np;
    }
    if(crossing_any(d, p, gl[d])) return INF;
    return abs(gl[d]-st);
}

double rec(int d, int pre) {
    double ans = calc(d);
    if(d<5) {
        rep(i, n) if(i!=pre) {
            ps[d+1][i] = ps[d][i];
            qs[d+1][i] = qs[d][i];
            rep(j, n) if(j!=i) {
                ps[d+1][j] = reflection(ps[d][i], qs[d][i], ps[d][j]);
                qs[d+1][j] = reflection(ps[d][i], qs[d][i], qs[d][j]);
            }
            gl[d+1] = reflection(ps[d][i], qs[d][i], gl[d]);
            ord[d] = i;
            ans = min(ans, rec(d+1, i));
        }
    }
    return ans;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        int x, y;
        rep(i, n) {
            scanf("%d%d", &x, &y);
            ps[0][i] = P(x, y);
            scanf("%d%d", &x, &y);
            qs[0][i] = P(x, y);
        }
        scanf("%d%d", &x, &y);
        gl[0] = P(x, y);
        scanf("%d%d", &x, &y);
        st = P(x, y);
        const double ans = rec(0, -1);
        printf("%.9f\n", ans);
    }
}

