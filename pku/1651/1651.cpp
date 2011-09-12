#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[200], dp[200][200];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    for(int w=2; w<n; w++) rep(l, n-w) {
        const int r = l+w;
        dp[l][r] = INT_MAX;
        for(int i=l+1; i<r; i++) {
            dp[l][r] = min(dp[l][r], dp[l][i]+dp[i][r]+a[l]*a[i]*a[r]);
        }
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}
