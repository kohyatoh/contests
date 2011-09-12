#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct RMQ {
    int n, dp[16][60000];
    void init(int _n, int *a) {
        n = _n;
        rep(i, n) dp[0][i] = a[i];
        int w = 1;
        rep(k, 15) {
            rep(i, n-2*w+1) {
                dp[k+1][i] = std::min(dp[k][i], dp[k][i+w]);
            }
            w *= 2;
        }
    }
    // return min([a[i] for i in [l, r)])
    int min(int l, int r) {
        int ix=0, w=1;
        while(w*2<r-l) ix++, w*=2;
        return std::min(dp[ix][l], dp[ix][r-w]);
    }
};

int n, a[50000], of[100001];
RMQ rmin, rmax;

int rec(int l, int r) {
    if(l>=r) return -1;
    int ans = -1;
    const int ix = of[-rmax.min(l, r)];
    if(l<ix) {
        const int jx = of[rmin.min(l, ix)];
        if(ix!=jx) ans = ix-jx;
        ans = max(ans, rec(l, jx));
    }
    ans = max(ans, rec(ix+1, r));
    return ans;
}

int main() {
    while(scanf("%d", &n)!=EOF) {
        rep(i, n) scanf("%d", a+i);
        rep(i, n) of[a[i]] = i;
        rmin.init(n, a);
        rep(i, n) a[i] = -a[i];
        rmax.init(n, a);
        printf("%d\n", rec(0, n));
    }
    return 0;
}
