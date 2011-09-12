#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k;
long long dp[400][400];

int main() {
    dp[0][0] = 1;
    rep(i, 300) rep(j, 300) if(j>0) {
        dp[i][j] += dp[i][j-1];
        if(i>=j) dp[i][j] += dp[i-j][j];
    }
    for(;;) {
        scanf("%d%d", &n, &k);
        if(n==0 && k==0) return 0;
        printf("%lld\n", dp[n][k]-dp[n][k-1]);
    }
    return 0;
}

