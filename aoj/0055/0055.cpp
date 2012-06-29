#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    double a[16];
    while (scanf("%lf", a) != EOF) {
        rep (i, 10) a[i+1] = i%2 ? a[i]/3 : a[i]*2;
        double ans = 0;
        rep (i, 10) ans += a[i];
        printf("%.8f\n", ans);
    }
    return 0;
}
