#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, px[200000], py[200000];
int m, qx[200000], qy[200000];

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d%d", px+i, py+i);
    scanf("%d", &m);
    rep (i, m) scanf("%d%d", qx+i, qy+i);
    rep (_, 2) {
        vector<int> xs(n+m+2);
        rep (i, n) xs[i] = px[i];
        rep (i, m) xs[n+i] = qx[i];
        xs[n+m] = -2000000000;
        xs[n+m+1] = +2000000000;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        vector<double> ym(xs.size(), 1e100);
        vector<double> yM(xs.size(), -1e100);
        int ix = lower_bound(xs.begin(), xs.end(), px[0]) - xs.begin();
        rep (i, n) {
            const int j = (i+1)%n;
            if (px[i] == px[j]) {
                ym[ix] = min(ym[ix], (double)min(py[i], py[j]));
                yM[ix] = max(yM[ix], (double)max(py[i], py[j]));
            }
            else {
                const int dix = px[i] < px[j] ? 1 : -1;
                for (;; ix+=dix) {
                    const double dx = xs[ix] - px[i];
                    const double y = py[i] + dx * (py[j]-py[i]) / (px[j]-px[i]);
                    ym[ix] = min(ym[ix], y);
                    yM[ix] = max(yM[ix], y);
                    if (xs[ix] == px[j]) break;
                }
            }
        }
        rep (i, m) {
            const int ix = lower_bound(xs.begin(), xs.end(), qx[i]) - xs.begin();
            if (qy[i] <= ym[ix] || qy[i] >= yM[ix]) {
                puts("NO");
                return 0;
            }
        }
        rep (i, n) swap(px[i], py[i]);
        rep (i, m) swap(qx[i], qy[i]);
    }
    puts("YES");
    return 0;
}
