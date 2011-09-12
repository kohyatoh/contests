#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define EPS (1e-10)
double pi=atan2(0.0, -1.0);

double calc(double r, double t) {
    if(t<0) return pi*r*r-calc(r, -t);
    double theta=acos(t/r), y=r*sin(theta);
    return theta*r*r-t*y;
}

int main() {
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
    double ans, d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if(r1+r2<=d-EPS) ans=0;
    else if(d+min(r1, r2)<=max(r1, r2)-EPS) ans=pi*min(r1, r2)*min(r1, r2);
    else {
        double t=(r1*r1-r2*r2+d*d)/(2*d);
        ans=calc(r1, t)+calc(r2, d-t);
    }
    printf("%.3f\n", ans);
    return 0;
}
