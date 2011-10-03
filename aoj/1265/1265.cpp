#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1e100)
#define EPS (1e-5)
typedef complex<double> P;
inline double sq(double a) { return a*a; }

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }
inline P unit(const P& p) { return 1/abs(p)*p; }
int ccw(const P& a, P b, P c) {
    b -= a; c -= a;
    if(cross(b, c) > 0) return 1;
    if(cross(b, c) < 0) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

inline double intersectSP(const P& s0, const P& s1, const P& p) {
    return abs(s0-p)+abs(s1-p)-abs(s1-s0) < EPS;
}

P projection(const P& l0, const P& l1, const P& p) {
    const double t = dot(p-l0, l0-l1) / norm(l0-l1);
    return l0 + t*(l0-l1);
}

double distanceSP(const P& s0, const P& s1, const P& p) {
    const P r = projection(s0, s1, p);
    if(intersectSP(s0, s1, r)) return abs(r-p);
    return min(abs(s0-p), abs(s1-p));
}

bool intersectSS(const P & s0, const P& s1, const P& t0, const P& t1) {
    return ccw(s0, s1, t0)*ccw(s0, s1, t1) <= 0
        && ccw(t0, t1, s0)*ccw(t0, t1, s1) <= 0;
}

P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    if(abs(A)<EPS && abs(B)<EPS) return m0;
    return m0+B/A*(m1-m0);
}

double distanceSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    if(intersectSS(s0, s1, t0, t1)) return 0;
    return min(min(distanceSP(s0, s1, t0), distanceSP(s0, s1, t1)),
               min(distanceSP(t0, t1, s0), distanceSP(t0, t1, s1)));
}

vector<P> crosspointsCL(const P& p, double r, const P& l0, const P& l1) {
    vector<P> v;
    const P cp(crosspoint(p, p+(l1-l0)*P(0, 1), l0, l1));
    if(abs(cp-p)<EPS) {
        const P dir(r*unit(l1-l0));
        v.push_back(p+dir); v.push_back(p-dir);
    }
    else if(abs(cp-p)<r+EPS) {
        const double a = sqrt(sq(r)-norm(p-cp));
        const P dir(a*unit(cp-p)*P(0, 1));
        v.push_back(cp+dir); v.push_back(cp-dir);
    }
    return v;
}

bool contains(const vector<P>& ps, const P& p) {
    bool in = false;
    rep(i, ps.size()) {
        P a(ps[i]-p), b(ps[(i+1)%ps.size()]-p);
        if(imag(a) > imag(b)) swap(a, b);
        if(imag(a) <= 0 && 0 < imag(b) && cross(a, b) < 0) in = !in;
        if(cross(a, b)==0 && dot(a, b) <= 0) return true; // 'on'
    }
    return in;
}

double L;
int n[2], xo[2][20], yo[2][20];
P po[2][20];

bool check(double dx) {
    vector<P> pm[2];
    rep(i, n[0]) pm[0].push_back(po[0][i]);
    rep(i, n[1]) pm[1].push_back(po[1][i] + P(dx, 0));
    rep(k, 2) rep(i, n[k]) if(contains(pm[1-k], pm[k][i])) return false;
    rep(i, n[0]) rep(j, n[1]) if(abs(pm[1][j]-pm[0][i])<L-EPS) return false;
    rep(k, 2) rep(i, n[k]) {
        const int j = (i+1)%n[k];
        rep(a, n[1-k]) {
            if(distanceSP(pm[k][i], pm[k][j], pm[1-k][a])<L-EPS) return false;
        }
    }
    rep(i, n[0]) rep(j, n[1]) {
        const int it = (i+1)%n[0];
        const int jt = (j+1)%n[1];
        if(distanceSS(pm[0][i], pm[0][it], pm[1][j], pm[1][jt])<L-EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    for(;;) {
        scanf("%lf", &L);
        if(fabs(L)<EPS) return 0;
        rep(k, 2) {
            scanf("%d", n+k);
            rep(i, n[k]) scanf("%d%d", xo[k]+i, yo[k]+i);
            rep(i, n[k]) po[k][i] = P(xo[k][i], yo[k][i]);
        }
        vector<double> cands;
        rep(i, n[0]) rep(j, n[1]) cands.push_back(xo[0][i]-xo[1][j]);
        rep(i, n[0]) rep(j, n[1]) {
            const double y = yo[1][j];
            vector<P> ps(crosspointsCL(po[0][i], L, P(-1000, y), P(1000, y)));
            rep(k, ps.size()) cands.push_back(ps[k].real()-xo[1][j]);
        }
        rep(k, 2) rep(i, n[k]) {
            const int j = (i+1)%n[k];
            rep(a, n[1-k]) {
                const P dir(L*unit(po[k][j]-po[k][i])*P(0, 1));
                vector<P> ps;
                ps.push_back(po[1-k][a]+dir);
                ps.push_back(po[1-k][a]-dir);
                rep(b, ps.size()) {
                    const double y = yo[k][i];
                    const P cp(crosspoint(ps[b], ps[b]+(po[k][j]-po[k][i]),
                                P(-1000, y), P(1000, y)));
                    if(k) cands.push_back(cp.real()-xo[k][i]);
                    else cands.push_back(xo[k][i]-cp.real());
                }
            }
        }
        sort(cands.begin(), cands.end());
        cands.erase(unique(cands.begin(), cands.end()), cands.end());
        double ans = INF;
        rep(k, cands.size()) if(check(cands[k])) {
            double xmin = INF, xmax = -INF;
            rep(i, n[0]) {
                xmin = min(xmin, (double)xo[0][i]);
                xmax = max(xmax, (double)xo[0][i]);
            }
            rep(i, n[1]) {
                xmin = min(xmin, (double)xo[1][i]+cands[k]);
                xmax = max(xmax, (double)xo[1][i]+cands[k]);
            }
            ans = min(ans, xmax-xmin);
        }
        printf("%.12f\n", ans);
    }
}

