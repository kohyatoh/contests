#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[512][512], b[512][512], dp[512][512];

int solve() {
    rep(k, n) {
        int s = 0, mx = 0;
        rep(i, m) s += b[k][i];
        rep(i, m+1) {
            mx = max(mx, dp[k][i]);
            dp[k+1][i] = s + mx;
            s += a[k][i] - b[k][i];
        }
    }
    int ans = 0;
    rep(i, m+1) ans = max(ans, dp[n][i]);
    return ans;
}

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) rep(j, m) scanf(" %d", a[i]+j);
        rep(i, n) rep(j, m) scanf(" %d", b[i]+j);
        printf("%d\n", solve());
    }
}
