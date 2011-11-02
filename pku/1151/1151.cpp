#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define fst first
#define snd second

int n;
double x1[200], y1[200], x2[200], y2[200];

int main() {
    for(int _q=0;; _q++) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%lf%lf%lf%lf", x1+i, y1+i, x2+i, y2+i);
        vector<double> xs;
        rep(i, n) {
            xs.push_back(x1[i]);
            xs.push_back(x2[i]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        double ans = 0;
        rep(k, xs.size()-1) {
            vector<pair<double, double> > ys;
            rep(i, n) if(x1[i]<=xs[k] && xs[k+1]<=x2[i]) {
                ys.push_back(mp(y1[i], y2[i]));
            }
            sort(ys.begin(), ys.end());
            int m = 0;
            rep(i, ys.size()) {
                if(i==0 || ys[i].fst>ys[m-1].snd) ys[m++] = ys[i];
                else ys[m-1].snd = max(ys[m-1].snd, ys[i].snd);
            }
            double r = 0;
            rep(i, m) r += ys[i].snd - ys[i].fst;
            ans += (xs[k+1]-xs[k])*r;
        }
        printf("Test case #%d\n", _q+1);
        printf("Total explored area: %.2f\n", ans);
        printf("\n");
    }
}
