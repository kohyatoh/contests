#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1<<30)
int T, m, n, s, pb[100][101], r[100], p[100], dp[200][200];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &m, &n, &s);
        rep(i, m) {
            rep(j, n) scanf("%d", pb[i]+j+1);
            scanf("%d%d", r+i, p+i);
        }
        rep(i, 200) rep(j, 200) dp[i][j]=-INF;
        dp[0][0]=0;
        rep(i, m) rep(j, n+1) rep(k, n-j+1) {
            int cost = pb[i][k]*(r[i]-s*k) + (100-pb[i][k])*(-p[i]);
            dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j]+cost);
        }
        int mp=-INF, mk=0;;
        rep(k, n+1) mp = max(mp, dp[m][k]);
        printf("%d\n", mp);
        rep(k, n+1) if(mp==dp[m][k]) {
            if(mk++) putchar(' ');
            printf("%d", k);
        }
        putchar('\n');
    }
}

