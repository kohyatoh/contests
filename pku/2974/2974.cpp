#include <stdio.h>
#include <math.h>
#include <valarray>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define EPS (1e-9)

struct P {
    double x, y, z;
    P() {}
    P(double x, double y, double z) : x(x), y(y), z(z) {}
};
inline P operator-(P a, const P& b) {
    return P(a.x-b.x, a.y-b.y, a.z-b.z);
}
inline double dot(const P& a, const P& b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}
inline P cross(const P& a, const P& b) {
    return P(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
inline double norm(const P& a) { return dot(a, a); }
inline double abs(const P& a) { return sqrt(norm(a)); }

int n;
P ps[40];

bool check(const P& a, const P& b, const P& c) {
    P cr(cross(b-a, c-a));
    int sign = 0;
    rep(i, n) {
        const int x = dot(cr, ps[i]-a);
        if(x!=0) {
            const int s = x>0 ? 1 : -1;
            if(sign==0) sign = s;
            else if(sign!=s) return false;
        }
    }
    return true;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            ps[i] = P(x, y, z);
        }
        double ans = 0;
        rep(i, n) rep(j, i) rep(k, j) if(check(ps[i], ps[j], ps[k])) {
            ans += abs(cross(ps[k]-ps[i], ps[j]-ps[i]))/2;
        }
        printf("%.0f\n", ans);
    }
}
