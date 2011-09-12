#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, f[50][50];
unsigned long long dp[50][50];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==-1) return 0;
        rep(i, n) rep(j, n) {
            char ch;
            scanf(" %c", &ch);
            f[i][j]=ch-'0';
        }
        rep(i, n) rep(j, n) dp[i][j]=0;
        dp[0][0]=1;
        rep(i, n) rep(j, n) if(f[i][j]) {
            if(i+f[i][j]<n) dp[i+f[i][j]][j]+=dp[i][j];
            if(j+f[i][j]<n) dp[i][j+f[i][j]]+=dp[i][j];
        }
        printf("%lld\n", dp[n-1][n-1]);
    }
}

