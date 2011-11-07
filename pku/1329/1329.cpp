#include <stdio.h>
#include <math.h>
#include <complex>
#include <string>
using namespace std;
typedef complex<double> P;
#define EPS (1e-9)

P scanP() {
    double x, y;
    scanf(" %lf%lf", &x, &y);
    return P(x, y);
}

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
const P rot90(0, 1);

P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    if(abs(A)<EPS && abs(B)<EPS) return m0;
    if(abs(A)<EPS) throw 0;
    return m0+B/A*(m1-m0);
}

string f(double d) {
    static char buf[128];
    sprintf(buf, "%c %.3f", d>=0 ? '+' : '-', fabs(d));
    return buf;
}

int main() {
    double x, y;
    while(scanf(" %lf%lf", &x, &y)!=EOF) {
        P p1(x, y);
        P p2(scanP());
        P p3(scanP());
        P m1(0.5*(p1+p2));
        P m2(0.5*(p2+p3));
        P p(crosspoint(m1, m1+(p2-p1)*rot90, m2, m2+(p3-p2)*rot90));
        const double x = -p.real(), y = -p.imag(), r = abs(p-p1);
        printf("(x %s)^2 + (y %s)^2 = %.3f^2\n",
                f(x).c_str(), f(y).c_str(), r);
        printf("x^2 + y^2 %sx %sy %s = 0\n",
                f(2*x).c_str(), f(2*y).c_str(), f(x*x+y*y-r*r).c_str());
        printf("\n");
    }
    return 0;
}
