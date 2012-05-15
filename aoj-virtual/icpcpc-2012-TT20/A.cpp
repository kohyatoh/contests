#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define INF (1<<28)

int n, t, w, d[32], v[32];
int dp[32][32][1024];
pair<int, int> pre[32][32][1024];

int main() {
    int T = 0;
    while (scanf("%d%d", &t, &w) != EOF) {
        if (T++) puts("");
        scanf("%d", &n);
        rep (i, n) scanf("%d%d", d+i, v+i);
        rep (i, 32) rep (j, 32) rep (k, 1024) dp[i][j][k] = -1;
        dp[n][0][0] = 0;
        for (int k = n-1; k >= 0; k--) {
            rep (i, n+1) rep (j, t+1) {
                dp[k][i][j] = dp[k+1][i][j];
                pre[k][i][j] = mp(i, j);
            }
            rep (i, n+1) rep (j, t+1) if (dp[k+1][i][j] >= 0) {
                const int a = 3*w*d[k];
                if (j+a <= t && dp[k][i+1][j+a] < dp[k+1][i][j] + v[k]) {
                    dp[k][i+1][j+a] = dp[k+1][i][j] + v[k];
                    pre[k][i+1][j+a] = mp(i, j);
                }
            }
        }
        int ans = 0, cn = 0, cw = 0;
        rep (i, n+1) rep (j, t+1) if (dp[0][i][j] > ans) {
            ans = dp[0][i][j];
            cn = i;
            cw = j;
        }
        printf("%d\n", ans);
        printf("%d\n", cn);
        rep (k, n) {
            const int nn = pre[k][cn][cw].first;
            const int nw = pre[k][cn][cw].second;
            if (nn != cn) {
                printf("%d %d\n", d[k], v[k]);
                cn = nn;
                cw = nw;
            }
        }
    }
    return 0;
}
