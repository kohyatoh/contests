#include <stdio.h>
#include <math.h>
inline double sq(double a) { return a*a; }
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const double pi = atan2(0.0, -1.0);
double R;
int n;

double f(double r) {
    return n*acos(1-sq(2*r)/sq(R-r)/2);
}

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        scanf("%lf%d", &R, &n);
        double l=0, r=R;
        rep(i, 100) {
            const double mid = (l+r)/2;
            if(f(mid)<2*pi) l = mid;
            else r = mid;
        }
        printf("Scenario #%d:\n", _q+1);
        printf("%.3f\n",  l);
        printf("\n");
    }
    return 0;
}
