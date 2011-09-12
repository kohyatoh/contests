#include <stdio.h>
#include <math.h>

double pi=atan2(0, -1);

int main() {
    double l, t, c;
    for(;;) {
        scanf("%lf%lf%lf", &l, &t, &c);
        if(l<0) return 0;
        double ll=(1+t*c)*l;
        double lt=0, ht=pi, mt;
        for(int q=0; q<100; q++) {
            mt = (lt+ht)/2;
            double r=l/2/sin(mt);
            if(r*mt<ll/2) lt=mt;
            else ht=mt;
        }
        double ans=0;
        if(lt>1e-8) ans = l/2/sin(lt)*(1-cos(lt));
        printf("%.3f\n", ans);
    }
}

