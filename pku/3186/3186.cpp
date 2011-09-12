#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, v[2048], dp[2048][2048];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", v+i);
    dp[0][0] = 0;
    rep(i, n) rep(j, i+1) {
        const int tx = n-1-i+j;
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+v[tx]*(i+1));
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+v[j]*(i+1));
    }
    int ans = 0;
    rep(i, n+1) ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}

