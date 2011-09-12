#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
double x0, y0, xp, yp, x, y;

int main() {
    while(scanf("%d", &n)!=EOF) {
        printf("%d", n);
        scanf("%lf%lf", &x0, &y0);
        xp=x0, yp=y0;
        rep(i, n-1) {
            scanf("%lf%lf", &x, &y);
            printf(" %.6f %.6f", (x+xp)/2, (y+yp)/2);
            xp=x, yp=y;
        }
        printf(" %.6f %.6f\n", (x0+xp)/2, (y0+yp)/2);
    }
    return 0;
}
