#include <stdio.h>
#include <iostream>
#include <complex>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;
#define INF (1e100)
#define EPS (1e-10)
const double pi = atan2(0.0, -1.0);

P unit(double t) { return P(cos(t), sin(t)); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b -= a, c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}
bool intersectSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    return ccw(s0, s1, t0) * ccw(s0, s1, t1) <= 0
        && ccw(t0, t1, s0) * ccw(t0, t1, s1) <= 0;
}
bool intersectSP(const P& s0, const P& s1, const P& p) {
    return abs(s0-p) + abs(s1-p) - abs(s1-s0) < EPS;
}
P projection(const P& l0, const P& l1, const P& p) {
    const double t = dot(p-l0, l0-l1) / norm(l0-l1);
    return l0 + t*(l0-l1);
}
double distanceSP(const P& s0, const P& s1, const P& p) {
    const P r = projection(s0, s1, p);
    if (intersectSP(s0, s1, r)) return abs(r-p);
    return min(abs(s0-p), abs(s1-p));
}
double distanceSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    if (intersectSS(s0, s1, t0, t1)) return 0;
    return min(min(distanceSP(s0, s1, t0), distanceSP(s0, s1, t1)),
               min(distanceSP(t0, t1, s0), distanceSP(t0, t1, s1)));
}

int N, M, L;
P ps[128][8];
double xs[128], ys[128], as[128], rs[128];
double g[128][128], dp[128];
int vis[128];

double solve() {
    rep (i, N) dp[i] = INF;
    rep (i, N) vis[i] = 0;
    dp[M] = 0;
    rep (i, N) {
        int at = -1;
        rep (i, N) if (vis[i] == 0) at = i;
        rep (i, N) if (vis[i] == 0 && dp[i] < dp[at]) at = i;
        vis[at] = 1;
        rep (i, N) if (vis[i] == 0) dp[i] = min(dp[i], dp[at] + g[at][i]);
    }
    return dp[L];
}

int main() {
    for (;;) {
        scanf("%d%d%d", &N, &M, &L);
        if (N == 0) return 0;
        M--, L--;
        rep (i, N) scanf("%lf%lf%lf%lf", xs+i, ys+i, as+i, rs+i);
        rep (i, N) rep (k, 5) {
            const double t = (as[i]+90+k*144) * pi / 180.0;
            ps[i][k] = P(xs[i], ys[i]) + rs[i] * unit(t);
        }
        rep (i, N) rep (j, i) {
            g[i][j] = g[j][i] = INF;
            rep (a, 5) rep (b, 5) {
                const double d = distanceSS(ps[i][a], ps[i][(a+1)%5],
                                            ps[j][b], ps[j][(b+1)%5]);
                g[i][j] = g[j][i] = min(g[i][j], d);
            }
        }
        printf("%.9f\n", solve());
    }
}
