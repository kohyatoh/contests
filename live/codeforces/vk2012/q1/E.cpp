#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<30)
inline void cmin(int &a, int b) { if (a > b) a = b; }

int n, k, t[4096], d[4096], dp[4096][4096];

int main() {
    scanf("%d%d", &n, &k);
    rep (i, n) scanf("%d%d", t+i, d+i);
    t[n] = 86401;
    rep (i, 4096) rep (j, 4096) dp[i][j] = INF;
    dp[0][0] = 1;
    int ans = 0;
    rep (i, n+1) rep (j, k+1) {
        ans = max(ans, t[i] - dp[i][j]);
        cmin(dp[i+1][j], max(dp[i][j], t[i]) + d[i]);
        cmin(dp[i+1][j+1], dp[i][j]);
    }
    printf("%d\n", ans);
    return 0;
}
