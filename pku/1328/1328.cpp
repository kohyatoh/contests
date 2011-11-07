#include <stdio.h>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define fst first
#define snd second

pair<double, double> f[2000];

int main() {
    for(int _q=0;; _q++) {
        int n;
        double r;
        scanf(" %d%lf", &n, &r);
        if(n==0) return 0;
        bool ok = true;
        rep(i, n) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            if(y>r) ok = false;
            const double z = sqrt(r*r-y*y);
            f[i] = mp(x+z, x-z);
        }
        int ans = -1;
        if(ok) {
            sort(f, f+n);
            double w = -1e100;
            ans = 0;
            rep(i, n) if(w<f[i].snd) {
                ans++;
                w = f[i].fst;
            }
        }
        printf("Case %d: %d\n", _q+1, ans);
    }
}
