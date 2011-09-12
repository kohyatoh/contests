#include <stdio.h>
#include <math.h>

int main() {
    double x, y, pi=atan2(0, -1);
    int n;
    scanf("%d", &n);
    for(int p=1; p<=n; p++) {
        scanf("%lf%lf", &x, &y);
        double s=0.5*pi*(x*x+y*y);
        printf("Property %d: This property will begin eroding in year %d.\n", p, (int)s/50+1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
