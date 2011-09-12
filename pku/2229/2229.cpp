#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define MOD (1000000000)
int n, dp[1048576];

int main() {
    scanf("%d", &n);
    dp[0] = 1;
    for(int b=2; b<=n; b*=2) rep(i, n-b+1) dp[i+b]=(dp[i+b]+dp[i])%MOD;
    int ans=0;
    rep(i, n+1) ans=(ans+dp[i])%MOD;
    printf("%d\n", ans);
    return 0;
}
