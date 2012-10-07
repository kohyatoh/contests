#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<28)

int n, m, a[64], b[64], c[64];
int f[64][10][10], dp[64][64][10];

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) scanf("%d%d%d", a+i, b+i, c+i);
    rep (k, 64) rep (x, 10) rep (y, 10) {
        f[k][x][y] = c[k];
        rep (i, x+1) rep (j, y+1) if (1 <= i+j && i+j <= 8) {
            f[k][x][y] = max(f[k][x][y], a[k]*j + b[k]*i);
        }
    }
    rep (i, 64) rep (j, 64) rep (k, 10) dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    rep (k, n) rep (x, m+1) rep (i, min(8, x)+1) if (dp[k][x][i] > -INF) {
        rep (j, min(8, m-x)+1) {
            dp[k+1][x+j][j] = max(dp[k+1][x+j][j], dp[k][x][i]+f[k][i][j]);
        }
    }
    int ans = -INF;
    rep (x, m+1) rep (i, 10) ans = max(ans, dp[n][x][i]);
    printf("%d\n", ans);
    return 0;
}
