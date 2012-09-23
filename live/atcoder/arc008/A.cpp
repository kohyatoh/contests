#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dp[100];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 1<<30;
    dp[0] = 0;
    rep (i, 100) if (i > 0) {
        dp[i] = dp[i-1] + 15;
        if (i >= 10) dp[i] = min(dp[i], dp[i-10] + 100);
        if (i >= n) ans = min(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
