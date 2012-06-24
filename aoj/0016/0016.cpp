#include <stdio.h>
#include <complex>
using namespace std;
typedef complex<double> P;
const double pi = atan2(0.0, -1.0);

P unit(double t) { return P(cos(t), sin(t)); }

int main() {
    P cp(0, 0);
    int cd = 90;
    for (;;) {
        int L, d;
        scanf("%d,%d", &L, &d);
        if (L == 0 && d == 0) break;
        cp += (double)L*unit(pi*cd/180);
        cd -= d;
    }
    printf("%d\n%d\n", (int)cp.real(), (int)cp.imag());
    return 0;
}
