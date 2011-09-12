#include <stdio.h>
#include <complex>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;

int n;
P p[400];

int kount(const P& z) {
    int c = 0;
    rep(i, n) if(norm(p[i]-z)<1+1e-8) c++;
    return c;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            p[i] = P(x, y);
        }
        int ans = 1;
        rep(i, n) rep(j, i) {
            const P dir = p[i]-p[j];
            const double h = abs(dir)/2;
            if(h>1) continue;
            const P dz = sqrt(1-h*h)/(h*2)*P(-dir.imag(), dir.real());
            ans = max(ans, kount(0.5*(p[i]+p[j])+dz));
            ans = max(ans, kount(0.5*(p[i]+p[j])-dz));
        }
        printf("%d\n", ans);
    }
}
