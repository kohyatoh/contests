#include <stdio.h>
#include <math.h>

int a, b, s, m, n;

int main() {
    for(;;) {
        scanf("%d%d%d%d%d", &a, &b, &s, &m, &n);
        if(a==0) return 0;
        double x=1.*m*a/s, y=1.*n*b/s;
        printf("%.2f %.2f\n", atan2(y, x)/atan2(0, -1)*180, sqrt(x*x+y*y));
    }
}
