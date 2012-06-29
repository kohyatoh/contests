#include <stdio.h>
#include <math.h>
#include <complex>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef complex<double> P;

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }

int n;
P ps[32];

int main() {
    double x, y;
    while (scanf("%lf,%lf", &x, &y) != EOF) ps[n++] = P(x, y);
    double s = 0;
    rep (i, n-1) s += cross(ps[i]-ps[0], ps[i+1]-ps[0]);
    printf("%.9f\n", fabs(s)/2);
    return 0;
}
