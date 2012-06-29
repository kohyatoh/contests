#include <stdio.h>
#include <math.h>
#include <complex>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef complex<double> P;
#define EPS (1e-12)

P unit(const P& p) { return 1/abs(p)*p; }
P rot90(const P& p) { return p*P(0, 1); }

int n;
P ps[128];

int f(const P& p) {
    int c = 0;
    rep (i, n) if (abs(p-ps[i]) <= 1+EPS) c++;
    return c;
}

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) {
            double x, y;
            scanf("%lf,%lf", &x, &y);
            ps[i] = P(x, y);
        }
        int ans = 1;
        rep (i, n) rep (j, i) {
            const double d = abs(ps[i]-ps[j]);
            if (d <= 2+EPS) {
                const P m = 0.5*(ps[i]+ps[j]);
                const P dir = rot90(unit(ps[j]-ps[i]));
                const double y = sqrt(max(0.0, 1-(d/2)*(d/2)));
                ans = max(ans, f(m+y*dir));
                ans = max(ans, f(m-y*dir));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
