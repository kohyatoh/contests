#include <stdio.h>
#include <math.h>
#include <complex>
using namespace std;
typedef complex<double> P;

double cross(const P& a, const P& b) { return imag(conj(a)*b); }
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    double a=cross(l1-l0, m1-m0), b=cross(l1-l0, l1-m0);
    return m0+b/a*(m1-m0);
}

int main() {
    int ab, ac, ad, bc, bd, cd;
    scanf("%d%d%d%d%d%d", &ab, &ac, &ad, &bc, &bd, &cd);
    double cp=(ac*ac+cd*cd-ad*ad)/(2.*cd);
    double cq=(ac*ac+bc*bc-ab*ab)/(2.*bc);
    double cos=(bc*bc+cd*cd-bd*bd)/(2.*bc*cd);
    P p(cp, 0), q(cq*cos, cq*sqrt(1-cos*cos));
    P o(crosspoint(p, p+P(0, 1), q, q+P(-sqrt(1-cos*cos), cos)));
    double h=sqrt(ac*ac-abs(o)*abs(o));
    double s=(bc+cd+bd)/2.;
    printf("%.4f\n", sqrt(s*(s-bc)*(s-cd)*(s-bd))*h/3.);
    return 0;
}
