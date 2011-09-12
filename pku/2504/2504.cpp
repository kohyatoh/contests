#include <stdio.h>
#include <math.h>
#include <complex>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const double pi = atan2(0, -1);
#define EPS (1e-08)
typedef complex<double> P;
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
P rot90(const P& p) { return P(imag(p), -real(p)); }
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    double A=cross(l1-l0, m1-m0), B=cross(l1-l0, l1-m0);
    if(abs(A)<EPS && abs(B)<EPS) return m0;
    return m0 + B/A*(m1-m0);
}

int main() {
    for(int q=0;; q++) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        double ax, ay, bx, by, cx, cy;
        scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
        P a(ax, ay), b(bx, by), c(cx, cy);
        P g(crosspoint(0.5*(a+b), 0.5*(a+b)+rot90(b-a),
                       0.5*(c+b), 0.5*(c+b)+rot90(b-c)));
        double r=abs(a-g), alpha=arg(a-g);
        double xmax=-1e100, xmin=1e100, ymax=-1e100, ymin=1e100;
        rep(i, n) {
            double x = real(g)+r*cos(alpha+2*pi*i/n);
            double y = imag(g)+r*sin(alpha+2*pi*i/n);
            xmax = max(xmax, x);
            xmin = min(xmin, x);
            ymax = max(ymax, y);
            ymin = min(ymin, y);
        }
        printf("Polygon %d: %.3f\n", q+1, (xmax-xmin)*(ymax-ymin));
    }
}

