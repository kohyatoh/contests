#include <stdio.h>

int n, a, b, c, dp[10000];

int main() {
    for (int i = 0; i < 10000; i++) dp[i] = -(1<<28);
    scanf("%d%d%d%d", &n, &a, &b, &c);
    dp[n] = 0;
    int ans = 1;
    for (int i = n; i >= 0; i--) {
        if (dp[i] < dp[i+a]+1) dp[i] = dp[i+a]+1;
        if (dp[i] < dp[i+b]+1) dp[i] = dp[i+b]+1;
        if (dp[i] < dp[i+c]+1) dp[i] = dp[i+c]+1;
        if (ans < dp[i]) ans = dp[i];
    }
    printf("%d\n", dp[0]);
    return 0;
}
