#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

inline int cross(int x1, int y1, int x2, int y2) { return x1*y2-x2*y1; }

int n, xs[1000], ys[1000];

int kount(int ix, int jx) {
    const int dx = xs[jx]-xs[ix], dy = ys[jx]-ys[ix];
    int c = 0;
    rep(i, n) if(cross(xs[i]-xs[ix], ys[i]-ys[ix], dx, dy)==0) c++;
    return c;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d", xs+i, ys+i);
        int ans = 0;
        rep(i, n) rep(j, i) ans = max(ans, kount(i, j));
        printf("%d\n", ans);
    }
}
