#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, dp[50][8];

int main() {
    dp[0][0]=1;
    rep(k, 30) rep(b, 8) rep(c, 8) if(!(b&c)) {
        int t=7^(b|c);
        if(t==0 || t==3 || t==6) dp[k+1][c]+=dp[k][b];
    }
    for(;;) {
        scanf("%d", &n);
        if(n==-1) return 0;
        printf("%d\n", dp[n][0]);
    }
}
