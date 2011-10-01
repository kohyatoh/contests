#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define EPS (1e-12)
inline double sq(double a) { return a*a; }

int n, a[10], b[10];

double at(int i, double y) {
    const int j = (i+1)%n;
    const double dx = a[j]-a[i], dy = b[j]-b[i];
    return a[i] + dx/dy*(y-b[i]);
}

double cut(double y) {
    vector<double> xs;
    rep(i, n) {
        const int j = (i+1)%n;
        if(b[i]==b[j]) continue;
        if(y <= min(b[i], b[j])) continue;
        if(y >= max(b[i], b[j])) continue;
        xs.push_back(at(i, y));
    }
    sort(xs.begin(), xs.end());
    if(xs.size()==4) return xs[3]-xs[2]+xs[1]-xs[0];
    else return xs.size()<2 ? 0 : xs.back()-xs.front();
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d", a+i, b+i);
        vector<double> ws;
        rep(i, n) ws.push_back(b[i]-EPS), ws.push_back(b[i]+EPS);
        sort(ws.begin(), ws.end());
        double ans = 0;
        rep(i, n) {
            const int j = (i+1)%n;
            if(b[i]==b[j]) {
                ans += (cut(b[i]-EPS) + cut(b[i]+EPS)) * abs(a[j]-a[i]);
            }
            else {
                const int u = min(b[i], b[j]), v = max(b[i], b[j]);
                rep(k, ws.size()-1) {
                    const double l = ws[k], r = ws[k+1];
                    if(r<u || l>v) continue;
                    const double d = sqrt(sq(r-l) + sq(at(i, r)-at(i, l)));
                    ans += (cut(l) + cut(r)) * d;
                }
            }
        }
        printf("%.12f\n", ans);
    }
}
