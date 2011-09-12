#include <stdio.h>
#include <math.h>

int main() {
    double t, d, h;
    for(;;) {
        t = d = h = -1000;
        char op;
        scanf(" %c", &op);
        if(op=='E') return 0;
        for(int i=0; i<2; i++) {
            if(i) scanf(" %c", &op);
            if(op=='T') scanf("%lf", &t);
            if(op=='D') scanf("%lf", &d);
            if(op=='H') scanf("%lf", &h);
        }
        if(t==-1000 || h==-1000) {
            const double e = 6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
            if(t==-1000) t = h - 0.5555*(e-10.0);
            else h = t + 0.5555*(e-10.0);
        }
        else {
            const double e = (h-t)/0.5555+10;
            const double y = (log(e)-log(6.11))/5417.7530;
            d = 1/(1/273.16-y) - 273.16;
        }
        printf("T %.1f D %.1f H %.1f\n", t, d, h);
    }
}
