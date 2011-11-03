#include <stdio.h>
#include <complex>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;

P unit(const P& p) { return 1.0/abs(p)*p; }

int n;
double xs[2000];
P ps[2000];

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        scanf("%d", &n);
        rep(i, n) scanf("%lf", xs+i);
        sort(xs, xs+n);
        rep(i, n) ps[i] = P(xs[i], 1.0);
        for(int k=n-1; k>0; k--) {
            rep(i, k) {
                const double a = abs(ps[i+1]-ps[i])/2;
                const double b = sqrt(4.0-a*a);
                ps[i] = 0.5*(ps[i]+ps[i+1])+b*unit(ps[i+1]-ps[i])*P(0, 1);
            }
        }
        printf("%d: %.4f %.4f\n", _q+1, ps[0].real(), ps[0].imag());
    }
    return 0;
}
