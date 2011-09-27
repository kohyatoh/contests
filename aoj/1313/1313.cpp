#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

vector<double> widths(const vector<int>& xs, int n, int *x, int *y) {
    vector<double> r;
    rep(i, xs.size()) {
        double miny = 1e100, maxy = -1e100;
        rep(j, n) {
            const int k = (j+1)%n;
            if(x[j]==xs[i]) {
                miny = min(miny, (double)y[j]);
                maxy = max(maxy, (double)y[j]);
            }
            else if(min(x[j], x[k])<=xs[i] && xs[i]<=max(x[j], x[k])) {
                const double dx = x[k]-x[j], dy = y[k]-y[j];
                const double cy = y[j]+dy/dx*(xs[i]-x[j]);
                miny = min(miny, cy);
                maxy = max(maxy, cy);
            }
        }
        r.push_back(maxy-miny);
    }
    return r;
}

double calc(double x, double y, double z1, double z2) {
    if(z1<z2) return x*y/2*z1 + x*y/2*(z2-z1)/3;
    else return x*y/2*z2 + y*(z1-z2)*x/3;
}

int m, mx[200], my[200], n, nx[200], nz[200];

int main() {
    for(;;) {
        scanf("%d%d", &m, &n);
        if(m==0 && n==0) return 0;
        rep(i, m) scanf("%d%d", mx+i, my+i);
        rep(i, n) scanf("%d%d", nx+i, nz+i);

        vector<int> xs;
        rep(i, m) xs.push_back(mx[i]);
        rep(i, n) xs.push_back(nx[i]);
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        vector<double> yw(widths(xs, m, mx, my));
        vector<double> zw(widths(xs, n, nx, nz));

        double ans = 0;
        rep(i, xs.size()-1) {
            const double x = xs[i+1]-xs[i];
            const double y1 = yw[i], y2 = yw[i+1];
            const double z1 = zw[i], z2 = zw[i+1];
            if(y1<0 || y2<0 || z1<0 || z2<0) continue;
            ans += (z1+z2)*x/2 * min(y1, y2);
            if(y1>y2) ans += calc(x, y1-y2, z1, z2);
            else ans += calc(x, y2-y1, z2, z1);
        }
        printf("%.12f\n", ans);
    }
}
