#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
double x, a[5000], c[5000];

double calc(double a1) {
    a[1]=a1;
    rep(i, n) a[i+2]=2*a[i+1]-a[i]+2*c[i];
    return a[n+1];
}

int main() {
    scanf("%d%lf%lf", &n, a, &x);
    rep(i, n) scanf("%lf", c+i);
    double l=-1000, r=1000, m;
    while(r-l>1e-4) {
        m=(l+r)/2;
        if(calc(m)<x) l=m;
        else r=m;
    }
    printf("%.2f\n", l);
    return 0;
}

