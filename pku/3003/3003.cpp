#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int n, a[50], dp[50][1024], pre[50][1024];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf(" %d", &n);
        rep(i, n) scanf("%d", a+i);
        rep(i, 50) rep(j, 1024) dp[i][j] = INF;
        dp[0][0] = 0;
        rep(k, n) rep(i, 1024) if(dp[k][i]<INF) {
            if(dp[k+1][i+a[k]] > max(dp[k][i], i+a[k])) {
                dp[k+1][i+a[k]] = max(dp[k][i], i+a[k]);
                pre[k+1][i+a[k]] = i;
            }
            if(i>=a[k] && dp[k+1][i-a[k]] > dp[k][i]) {
                dp[k+1][i-a[k]] = dp[k][i];
                pre[k+1][i-a[k]] = i;
            }
        }
        if(dp[n][0]==INF) puts("IMPOSSIBLE");
        else {
            string s;
            int cur = 0;
            for(int k=n; k>0; k--) {
                const int p = pre[k][cur];
                if(p<cur) s += 'U';
                else s += 'D';
                cur = p;
            }
            reverse(s.begin(), s.end());
            puts(s.c_str());
        }
    }
    return 0;
}
