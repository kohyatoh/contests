#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<28)

int n, a[32], dp[32][32][32];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        rep (i, n) scanf("%d", a+i);
        int mx = 0;
        rep (i, n) if (mx < a[i]) mx = a[i];
        rep (i, 32) rep (j, 32) rep (k, 32) dp[i][j][k] = INF;
        rep (i, 32) rep (j, 32) dp[i][j][0] = 0;
        rep (i, n) if (a[i] == mx) dp[i][i][1] = 0;
        for (int w = 1; w < n; w++) {
            for (int l = 0; l+w < n; l++) {
                const int r = l + w;
                const int m = r-l+1;
                for (int c = m; c > 0; c--) {
                    dp[l][r][c] = min(dp[l][r][c], dp[l][r][c+1]);
                    for (int x = l; x < r; x++) {
                        for (int i = 0; i <= c; i++) {
                            dp[l][r][c] = min(dp[l][r][c],
                                    dp[l][x][i]+dp[x+1][r][c-i]);
                        }
                    }
                    if (c >= (m+1)/2) {
                        dp[l][r][m] = min(dp[l][r][m], dp[l][r][c]+1);
                    }
                }
            }
        }
        printf("%d\n", dp[0][n-1][n]);
    }
    return 0;
}
