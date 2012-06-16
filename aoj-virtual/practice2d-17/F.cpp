// Oh, this is a fake solution!
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<int> P;

int bitcount(int a) {
    int c = 0;
    while (a) c++, a&=a-1;
    return c;
}

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }

inline bool intersectSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    if (max(real(s0), real(s1)) < min(real(t0), real(t1))) return false;
    if (max(real(t0), real(t1)) < min(real(s0), real(s1))) return false;
    if (max(imag(s0), imag(s1)) < min(imag(t0), imag(t1))) return false;
    if (max(imag(t0), imag(t1)) < min(imag(s0), imag(s1))) return false;
    return cross(s1-s0, t0-s0) * cross(s1-s0, t1-s0) <= 0
        && cross(t1-t0, s0-t0) * cross(t1-t0, s1-t0) <= 0;
}

int n, g[32], m[32];
P ps[32][32];

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) {
            int x, y;
            scanf("%d", m+i);
            rep (j, m[i]) {
                scanf("%d%d", &x, &y);
                ps[i][j] = P(x, y);
            }
        }
        memset(g, 0, sizeof(g));
        rep (i, n) g[i] |= 1<<i;
        rep (i, n) rep (j, m[i]-1) rep (x, i) rep (y, m[x]-1) {
            if (intersectSS(ps[i][j], ps[i][j+1], ps[x][y], ps[x][y+1])) {
                g[i] |= 1<<x, g[x] |= 1<<i;
            }
        }
        const int nn = 1<<n;
        int ans = 0;
        rep (b, nn) {
            bool f = true;
            rep (i, n) if ((b&(1<<i)) && (g[i]&b)!=b) {
                f = false;
                break;
            }
            if (f) ans = max(ans, bitcount(b));
        }
        printf("%d\n", ans);
    }
}
