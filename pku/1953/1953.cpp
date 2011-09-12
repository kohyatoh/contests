#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, dp[500];
int main() {
    dp[0]=1;
    dp[1]=2;
    rep(i, 50) dp[i+2] = dp[i+1] + dp[i];
    scanf("%d", &T);
    rep(i, T) {
        scanf("%d", &n);
        printf("Scenario #%d:\n%d\n\n", i+1, dp[n]);
    }
    return 0;
}

