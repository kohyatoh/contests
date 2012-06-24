#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int L[10], v1, v2;

int main() {
    while (scanf("%d", L) != EOF) {
        rep (i, 9) scanf(",%d", L+i+1);
        scanf(",%d,%d", &v1, &v2);
        double s = 0;
        rep (i, 10) s += L[i];
        const double t = s / (v1+v2);
        double x = t*v1;
        rep (i, 10) {
            if (x <= L[i]) {
                printf("%d\n", i+1);
                break;
            }
            x -= L[i];
        }
    }
    return 0;
}
