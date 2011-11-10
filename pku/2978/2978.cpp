#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int n, m, a[200], dp[200][6][1<<6];

int main() {
    for(;;) {
        scanf(" %d%d", &n, &m);
        if(n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        m++;
        const int mm = 1<<m;
        rep(i, 200) rep(j, 6) rep(k, 1<<6) dp[i][j][k] = INF;
        dp[0][0][0] = 0;
        rep(k, n) rep(x, m) rep(b, mm) {
            const int y = a[k];
            if(x==y) cmin(dp[k+1][x][b], dp[k][x][b]);
            else {
                cmin(dp[k+1][x][b], dp[k][x][b]+1);
                if((b&(1<<y))==0) cmin(dp[k+1][y][b|(1<<y)], dp[k][x][b]);
            }
        }
        int ans = INF;
        rep(x, m) rep(b, mm) cmin(ans, dp[n][x][b]);
        printf("%d\n", ans);
    }
}
