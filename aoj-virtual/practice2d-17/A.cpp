#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int M, I, K;
Int dp[32][32][32][24], cnt[32][32][32][24];

void pre() {
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    rep (i, 32) rep (j, 32) cnt[0][i][j][0] = 1;
    rep (k, 31) {
        const int f = 1<<k;
        rep (n, 31) rep (d, 31) rep (m, 21) {
            const int d0 = d + ((I&f)!=0), d1 = d + ((I&f)==0);
            const int m1 = (m+f) % 21;
            dp[k+1][n][d0][m] += dp[k][n][d][m];
            cnt[k+1][n][d0][m] += cnt[k][n][d][m];
            dp[k+1][n+1][d1][m1] += dp[k][n][d][m] + f*cnt[k][n][d][m];
            cnt[k+1][n+1][d1][m1] += cnt[k][n][d][m];
        }
    }
}

Int f(int x) {
    Int ans = 0;
    int n = 0, d = 0, m = 0, pre = 0;
    for (int k = 31; k >= 0; k--) {
        const int kk = 1<<k;
        if (x&kk) {
            if ((I&kk) && d+1 <= K && n <= M) {
                for (int i = 3; i < 21; i += 3) {
                    const int ix = (i+21-m) % 21;
                    ans += dp[k][M-n][K-d-1][ix] + pre*cnt[k][M-n][K-d-1][ix];
                }
            }
            if ((I&kk)==0 && d <= K && n <= M) {
                for (int i = 3; i < 21; i += 3) {
                    const int ix = (i+21-m) % 21;
                    ans += dp[k][M-n][K-d][ix] + pre*cnt[k][M-n][K-d][ix];
                }
            }
            n++;
            pre += kk;
            m = (m + kk) % 21;
        }
        d += (x&kk) != (I&kk);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        int x, y;
        scanf("%d%d%d%d%d", &x, &y, &M, &I, &K);
        M = min(M, 30);
        K = min(K, 30);
        pre();
        cout << "Case " << _q+1 << ": " << f(y+1) - f(x) << endl;
    }
    return 0;
}
