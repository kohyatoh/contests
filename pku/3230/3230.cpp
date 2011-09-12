#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int n, m, g[128][128], a[128][128], dp[128][128];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) rep(j, n) scanf("%d", g[i]+j);
        rep(i, m) rep(j, n) scanf("%d", a[i]+j);
        rep(i, 128) rep(j, 128) dp[i][j] = -INF;
        dp[0][0] = 0;
        rep(i, m) rep(j, n) rep(k, n) {
            dp[i+1][k] = max(dp[i+1][k], dp[i][j]-g[j][k]+a[i][k]);
        }
        int ans = 0;
        rep(i, n) ans = max(ans, dp[m][i]);
        printf("%d\n", ans);
    }
}
