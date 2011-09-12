#include <stdio.h>

int main() {
    double mw, mi, tw, ti, rmw, rmi, rt;
    for(;;) {
        scanf("%lf%lf%lf%lf", &mw, &mi, &tw, &ti);
        if(mw+mi==0) return 0;
        double e=4.19*tw*mw+2.09*ti*mi-335.0*mi;
        if(e>=0) {
            rmi = 0;
            rmw = mw+mi;
            rt = e/(4.19*rmw);
        }
        else {
            if(-335.0*(mw+mi)<e) {
                rmi =  -e/335.0;
                rmw = mw+mi-rmi;
                rt = 0;
            }
            else {
                rmi = mw+mi;
                rmw = 0;
                rt = (e+335.0*rmi)/(2.09*rmi);
            }
        }
        printf("%.1f g of ice and %.1f g of water at %.1f C\n", rmi, rmw, rt);
    }
}

