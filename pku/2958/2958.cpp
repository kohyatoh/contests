#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n[4], m[4], a[4][128][128], cnt[4][128][128], dp[4][128][128];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", m, n);
        rep(i, n[0]) rep(j, m[0]) scanf(" %d", a[0][i]+j);
        rep(k, 3) {
            n[k+1] = m[k];
            m[k+1] = n[k];
            rep(i, n[k]) rep(j, m[k]) a[k+1][m[k]-1-j][i] = a[k][i][j];
        }
        rep(k, 4) rep(i, n[k]) {
            int s = 0, c = 0;
            rep(j, m[k]) {
                dp[k][i][j] = s;
                cnt[k][i][j] = c;
                if(i>0) {
                    dp[k][i][j] += dp[k][i-1][j]+cnt[k][i-1][j];
                    cnt[k][i][j] += cnt[k][i-1][j];
                }
                c += a[k][i][j];
                s += c;
            }
        }
        rep(k, 3) rep(i, n[k]) rep(j, m[k]) dp[k+1][m[k]-1-j][i] += dp[k][i][j];
        int ans = dp[3][0][0];
        rep(i, n[3]) rep(j, m[3]) ans = min(ans, dp[3][i][j]);
        printf("%d blocks\n", ans);
    }
    return 0;
}

