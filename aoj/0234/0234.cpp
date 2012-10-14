#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if (a > b) a = b; }

int W, H, F, M, O, C[12][12], A[12][12];
int dp[12][12][12][2][64];

int main() {
    for (;;) {
        scanf("%d%d", &W, &H);
        if (W == 0 && H == 0) return 0;
        assert (3 <= W && W <= 10);
        assert (3 <= H && H <= 10);
        scanf("%d%d%d", &F, &M, &O);
        assert (1 <= F && F <= 10000);
        assert (3 <= M && M <= 50);
        rep (i, H) rep (j, W) {
            int c;
            scanf("%d", &c);
            if (c < 0) C[i][j] = -c, A[i][j] = 0;
            if (c >= 0) C[i][j] = 0, A[i][j] = c;
        }
        if (O <= 1) {
            puts("NA");
            continue;
        }
        rep (i, H) rep (j, W) rep (k, W) rep (l, 2) rep (m, M+1) {
            dp[i][j][k][l][m] = INF;
        }
        rep (i, W) dp[0][i][0][0][min(M, O-1+A[0][i])] = C[0][i];
        rep (k, H-1) rep (w, W) rep (i, W-w) rep (si, 2) rep (m, M+1) {
            const int j = i+w;
            if (i > 0) {
                const int d = si ? w+1 : 1;
                if (d < m) cmin(dp[k][i-1][w+1][0][min(M, m-d+A[k][i-1])],
                                dp[k][i][w][si][m] + C[k][i-1]);
            }
            if (j < W-1) {
                const int d = si ? 1 : w+1;
                if (d < m) cmin(dp[k][i][w+1][1][min(M, m-d+A[k][j+1])],
                                dp[k][i][w][si][m] + C[k][j+1]);
            }
            for (int x = i; x <= j; x++) {
                const int d = si ? j-x+1 : x-i+1;
                if (d < m) cmin(dp[k+1][x][0][0][min(M, m-d+A[k+1][x])],
                                dp[k][i][w][si][m] + C[k+1][x]);
            }
        }
        int ans = INF;
        rep (i, W) rep (m, M+1) cmin(ans, dp[H-1][i][0][0][m]);
        if (ans > F) puts("NA");
        else printf("%d\n", ans);
    }
}
