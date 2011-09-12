#include <stdio.h>
#include <math.h>

const double pi=atan2(0, -1);

int main() {
    double r, h, d1, A1, d2, A2;
    while(scanf("%lf%lf%lf%lf%lf%lf", &r, &h, &d1, &A1, &d2, &A2)!=EOF) {
        double a=sqrt(r*r+h*h);
        double theta=2*pi*r/a;
        double alpha=theta*fabs(A1-A2)/360.0;
        if(alpha>theta-alpha) alpha=theta-alpha;
        printf("%.2f\n", hypot(d1-d2*cos(alpha), d2*sin(alpha)));
    }
    return 0;
}
