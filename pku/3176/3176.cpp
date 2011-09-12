#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, dp[512][512];

int main() {
    scanf("%d", &n);
    rep(i, n) rep(j, i+1) scanf("%d", dp[i]+j);
    for(int i=n-2; i>=0; i--) rep(j, i+1) {
        dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
    }
    printf("%d\n", dp[0][0]);
    return 0;
}
