#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int k, m;
double sx[100], sy[100], sz[100], tx[100], ty[100], tz[100];
const double pi=atan2(0.0, -1.0), c2=4.0E8/pi/pi;

inline double sq(double x, double y, double z) { return x*x+y*y+z*z; }

int main() {
    for(;;) {
        scanf("%d%d", &k, &m);
        if(k==0 && m==0) return 0;
        rep(i, k) scanf("%lf%lf%lf", sx+i, sy+i, sz+i);
        rep(i, m) scanf("%lf%lf%lf", tx+i, ty+i, tz+i);
        int ans=0;
        rep(i, m) rep(j, k) {
            double a2=sq(tx[i]-sx[j], ty[i]-sy[j], tz[i]-sz[j]);
            double b2=sq(sx[j], sy[j], sz[j]);
            if(b2>=a2+c2) {
                ans++;
                break;
            }
        }
        printf("%d\n", ans);
    }
}
