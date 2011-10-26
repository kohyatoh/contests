#include <stdio.h>
#include <math.h>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double polygon_size(const vector<P>& vs) {
    double s = 0;
    rep(i, vs.size()-2) s += cross(vs[i+1]-vs[0], vs[i+2]-vs[0]);
    return fabs(s)/2;
}

int main() {
    for(;;) {
        int N;
        scanf("%d", &N);
        if(N<3) return 0;
        vector<P> vs;
        rep(i, N) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            vs.push_back(P(x, y));
        }
        double V;
        scanf("%lf", &V);
        printf("BAR LENGTH: %.2f\n", V/polygon_size(vs));
    }
}
