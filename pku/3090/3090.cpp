#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

int dp[1024];

int main() {
    dp[1] = 3;
    for(int i=2; i<1024; i++) {
        dp[i] += dp[i-1];
        for(int j=1; j<i; j++) if(gcd(i, j)==1) dp[i]+=2;
    }
    int T;
    scanf("%d", &T);
    rep(_t, T) {
        int n;
        scanf("%d", &n);
        printf("%d %d %d\n", _t+1, n, dp[n]);
    }
    return 0;
}
