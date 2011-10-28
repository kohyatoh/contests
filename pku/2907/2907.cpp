#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int diff(int x1, int y1, int x2, int y2) {
    return abs(x2-x1) + abs(y2-y1);
}

int Lx, Ly, sx, sy, n, xs[16], ys[16];
int dp[2000][16];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &Lx, &Ly);
        scanf("%d%d", &sx, &sy);
        scanf("%d", &n);
        rep(i, n) scanf("%d%d", xs+i, ys+i);
        const int nn = 1<<n;
        rep(i, nn) rep(j, n) dp[i][j] = INF;
        rep(i, n) dp[1<<i][i] = diff(sx, sy, xs[i], ys[i]);
        rep(b, nn) rep(i, n) if(dp[b][i]<INF) {
            rep(j, n) if((b&(1<<j))==0) {
                const int df = diff(xs[i], ys[i], xs[j], ys[j]);
                cmin(dp[b|(1<<j)][j], dp[b][i]+df);
            }
        }
        int ans = INF;
        rep(i, n) cmin(ans, dp[nn-1][i]+diff(sx, sy, xs[i], ys[i]));
        printf("The shortest path has length %d\n", ans);
    }
    return 0;
}
