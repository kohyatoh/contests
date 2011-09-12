#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
#define EPS (1e-10)

double cross(const P& a, const P& b) { return imag(conj(a)*b); }
P crosspoint(const P& a0, const P& a1, const P& b0, const P& b1) {
    double A=cross(a1-a0, b1-b0), B=cross(a1-a0, a1-b0);
    if(abs(A)<EPS && abs(B)<EPS) return a0;
    return b0+B/A*(b1-b0);
}

double x, y, c;

double calc(double d) {
    return imag(crosspoint(P(0, 0), P(d, sqrt(y*y-d*d)), P(d, 0), P(0, sqrt(x*x-d*d))));
}

int main() {
    while(scanf("%lf%lf%lf", &x, &y, &c)!=EOF) {
        double l=0, r=x<y?x:y, m;
        while(r-l>1e-5) {
            m=(l+r)/2;
            if(calc(m)>c) l=m;
            else r=m;
        }
        printf("%.3f\n", l);
    }
    return 0;
}
