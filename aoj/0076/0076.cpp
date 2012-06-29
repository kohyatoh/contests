#include <stdio.h>
#include <complex>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;

P ps[1024];

int main() {
    ps[0] = P(1, 0);
    rep (i, 1024) if (i) {
        ps[i] = ps[i-1] + P(0, -1) * -ps[i-1] / abs(ps[i-1]);
    }
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == -1) return 0;
        n--;
        printf("%.2f\n", ps[n].real());
        printf("%.2f\n", ps[n].imag());
    }
}
