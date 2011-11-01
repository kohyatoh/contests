#include <stdio.h>
#include <complex>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }

int ccw(const P& a, P b, P c) {
    b -= a; c -= a;
    if(cross(b, c) > 0) return 1;
    if(cross(b, c) < 0) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

bool intersectSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    return ccw(s0, s1, t0)*ccw(s0, s1, t1) <= 0
        && ccw(t0, t1, s0)*ccw(t0, t1, s1) <= 0;
}

P scanP() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return P(x, y);
}

int n, g[16][16];
P ps[16], qs[16];

int main() {
    for(;;) {
        scanf(" %d", &n);
        if(n==0) return 0;
        rep(i, n) {
            ps[i] = scanP();
            qs[i] = scanP();
        }
        rep(i, n) rep(j, n) {
            g[i][j] = intersectSS(ps[i], qs[i], ps[j], qs[j]);
        }
        rep(k, n) rep(i, n) rep(j, n) g[i][j] |= g[i][k]&g[k][j];
        for(;;) {
            int a, b;
            scanf("%d%d", &a, &b);
            if(a==0 && b==0) break;
            printf("%sCONNECTED\n", g[a-1][b-1] ? "" : "NOT ");
        }
    }
}
