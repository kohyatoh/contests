#include <stdio.h>
#include <math.h>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
inline double sq(double a) { return a*a; }
#define INF (1e100)
#define EPS (1e-9)

int n;
double hx, hy, mx, my, xs[32], ys[32], ds[32], ws[32][32];
pair<double, int> ns[32];

bool rec(int b, int at, double t) {
    if (b == (1<<n)-1) return true;
    rep (i, n) {
        const int ix = ns[i].second;
        if (b&(1<<ix)) continue;
        double nt = t + ws[at][ix];
        if (nt > ds[ix]-EPS) return false;
        if (rec(b|(1<<ix), ix, nt)) return true;
    }
    return false;
}

int main() {
    for (;;) {
        scanf("%d%lf%lf%lf%lf", &n, &hx, &hy, &mx, &my);
        if (n == 0) return 0;
        rep (i, n) scanf("%lf%lf", xs+i, ys+i);
        rep (i, n) ds[i] = sqrt(sq(xs[i]-mx) + sq(ys[i]-my));
        rep (i, n) ns[i] = mp(ds[i], i);
        sort(ns, ns+n);
        rep (i, n) rep (j, n) {
            ws[i][j] = sqrt(sq(xs[i]-xs[j]) + sq(ys[i]-ys[j]));
        }
        bool ans = false;
        rep (i, n) {
            double t = sqrt(sq(xs[i]-hx) + sq(ys[i]-hy));
            if (t < ds[i]-EPS && rec(1<<i, i, t)) { ans = true; break; }
        }
        puts(ans ? "YES" : "NO");
    }
}
