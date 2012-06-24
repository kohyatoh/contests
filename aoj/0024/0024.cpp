#include <stdio.h>
#include <math.h>
#define EPS (1e-12)

bool can(int n, double v) {
    double h = 5*n-5;
    return 9.8*sqrt(h/4.9) > v-EPS;
}

int main() {
    double v;
    while (scanf("%lf", &v) != EOF) {
        int l = 1, r = 1<<28;
        while (r-l>1) {
            const int mid = (l+r) / 2;
            if (can(mid, v)) r = mid;
            else l = mid;
        }
        printf("%d\n", r);
    }
    return 0;
}
