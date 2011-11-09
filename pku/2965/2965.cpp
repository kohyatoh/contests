#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int of[4], dp[5][16][16], pre[5][16][16], prz[5][16][16], cx[4];

int bitcount(int a) {
    int c = 0;
    while(a) c++, a&=a-1;
    return c;
}

int main() {
    rep(i, 4) rep(j, 4) {
        char ch;
        scanf(" %c", &ch);
        if(ch=='+') of[i] |= 1<<j;
    }
    rep(k, 5) rep(i, 16) rep(j, 16) dp[k][i][j] = INF;
    rep(i, 16) dp[0][i][0] = 0;
    rep(k, 4) rep(b, 16) rep(z, 16) if(dp[k][b][z]<INF) rep(x, 16) {
        const int bi = bitcount(x);
        int nb = of[k]^z;
        if(bi%2) nb ^= 15;
        if(nb==(b^x) && dp[k+1][nb][x^z]>dp[k][b][z]+bi) {
            dp[k+1][nb][x^z] = dp[k][b][z]+bi;
            pre[k+1][nb][x^z] = b;
            prz[k+1][nb][x^z] = z;
        }
    }
    int ans = INF, cur = 0, cus = -1;
    rep(i, 16) if(ans>dp[4][0][i]) ans = dp[4][0][i], cus = i;
    rep(k, 4) {
        const int nr = pre[4-k][cur][cus];
        const int ns = prz[4-k][cur][cus];
        cx[3-k] = cus^ns;
        cur = nr;
        cus = ns;
    }
    printf("%d\n", ans);
    rep(k, 4) rep(i, 4) if(cx[k]&(1<<i)) {
        printf("%d %d\n", k+1, i+1);
    }
    return 0;
}
