#include <stdio.h>
#include <math.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)
#define sq(x) ((x)*(x))

double pi=atan2(0, -1);

int n;
double la[1000], lo[1000], x[1000], y[1000], z[1000];

int main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf("%lf%lf", la+i, lo+i);
        x[i]=cos(la[i]/180*pi)*cos(lo[i]/180*pi);
        y[i]=cos(la[i]/180*pi)*sin(lo[i]/180*pi);
        z[i]=sin(la[i]/180*pi);
    }
    double mins=1e100;
    int mini;
    rep(i, n) {
        double s=0;
        rep(j, n) s=std::max(s, acos(1-(sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]))/2));
        if(mins>s) mins=s, mini=i;
    }
    printf("%.2f %.2f\n", la[mini], lo[mini]);
    return 0;
}
