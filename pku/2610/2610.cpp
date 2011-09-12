#include <stdio.h>
#include <math.h>

double gx, gy, dx, dy, x, y;

int main() {
    scanf("%lf%lf%lf%lf", &gx, &gy, &dx, &dy);
    while(scanf("%lf%lf", &x, &y)!=EOF) {
        if(hypot(gx-x, gy-y)*2<hypot(dx-x, dy-y)) {
            printf("The gopher can escape through the hole at (%.3f,%.3f).\n", x, y);
            return 0;
        }
    }
    printf("The gopher cannot escape.\n");
    return 0;
}
