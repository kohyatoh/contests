#include <stdio.h>
#include <complex>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;

double cross(const P& a, const P& b) { return imag(conj(a)*b); }

P ps[4];

bool is() {
    const double sig = cross(ps[1]-ps[0], ps[2]-ps[0]);
    rep (i, 4) {
        const int j = (i+1)%4;
        const int k = (i+2)%4;
        if (cross(ps[j]-ps[i], ps[k]-ps[i])*sig < 0) return false;
    }
    return true;
}

int main() {
    double x[4], y[4];
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                x, y, x+1, y+1, x+2, y+2, x+3, y+3) != EOF) {
        rep (i, 4) ps[i] = P(x[i], y[i]);
        puts(is() ? "YES" : "NO");
    }
    return 0;
}
