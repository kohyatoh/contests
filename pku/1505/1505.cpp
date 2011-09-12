#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1LL<<60)
typedef long long Int;
int T, n, m, p[500];
Int dp[800][800];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        rep(i, n) scanf("%d", p+i);
        rep(i, 800) rep(j, 800) dp[i][j]=INF;
        dp[m][n] = 0;
        for(int i=m-1; i>=0; i--) for(int j=i; j<=n-m+i; j++) {
            Int s=0;
            for(int k=1; k<=n-m+i+1-j && dp[i][j]>s; k++) {
                s += p[j+k-1];
                dp[i][j] = min(dp[i][j], max(s, dp[i+1][j+k]));
            }
        }
        for(int i=0, x=0; i<m; i++) {
            printf(i?" / %d":"%d", p[x++]);
            while(dp[i+1][x]>dp[0][0]) printf(" %d", p[x++]);
        }
        puts("");
    }
    return 0;
}
