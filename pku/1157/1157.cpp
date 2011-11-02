#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmax(int &a, int b) { if(a<b) a = b; }

int n, m, a[128][128], dp[128][128];

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) scanf("%d", a[i]+j);
    rep(i, 128) rep(j, 128) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i, n) rep(j, m) {
        for(int k=j; k<m; k++) cmax(dp[i+1][k+1], dp[i][j]+a[i][k]);
    }
    int ans = -INF;
    rep(i, m+1) cmax(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}
