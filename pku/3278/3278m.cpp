#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, dp[200000];

int main() {
    scanf("%d%d", &n, &k);
    rep(i, n+1) dp[i] = n-i;
    for(int i=n+1; i<=k; i++) {
        if(i%2) dp[i] = min(dp[i-1]+1, dp[(i+1)/2]+2);
        else dp[i] = min(dp[i-1]+1, dp[i/2]+1);
    }
    printf("%d\n", dp[k]);
    return 0;
}
