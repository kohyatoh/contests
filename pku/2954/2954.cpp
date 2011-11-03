#include <stdio.h>
#include <math.h>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;
#define INF (1<<28)
#define EPS (1e-9)

int xs[3], ys[3];

int main() {
    for(;;) {
        rep(i, 3) scanf("%d%d", xs+i, ys+i);
        bool any = false;
        rep(i, 3) if(xs[i] || ys[i]) any = true;
        if(!any) return 0;
        int xmin = INF, xmax = -INF;
        rep(i, 3) xmin = min(xmin, xs[i]);
        rep(i, 3) xmax = max(xmax, xs[i]);
        Int ans = 0;
        for(int x=xmin; x<=xmax; x++) {
            double ymin = INF, ymax = -INF;
            bool hit = false;
            rep(i, 3) {
                const int j = (i+1)%3;
                if(xs[i]==xs[j]) {
                    if(xs[i]==x) hit = true;
                }
                else if(min(xs[i], xs[j])<=x && x<=max(xs[i], xs[j])) {
                    const double dx = xs[j]-xs[i], dy = ys[j]-ys[i];
                    const double y = ys[i]+dy/dx*(x-xs[i]);
                    ymin = min(ymin, y);
                    ymax = max(ymax, y);
                }
            }
            if(!hit && floor(ymax-EPS)-ceil(ymin+EPS)+1>0) {
                ans += floor(ymax-EPS)-ceil(ymin+EPS)+1;
            }
        }
        cout << ans << endl;
    }
}
