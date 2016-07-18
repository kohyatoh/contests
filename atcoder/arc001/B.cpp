#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000];

int main() {
    for (int i = 0; i < 1000; i++) dp[i] = 5000;
    dp[0] = 0;
    for (int i = 0; i < 500; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        dp[i+5] = min(dp[i+5], dp[i] + 1);
        dp[i+10] = min(dp[i+10], dp[i] + 1);
    }
    int A, B;
    scanf("%d%d", &A, &B);
    int ans = 5000;
    for (int t = -100; t <= 100; t++) {
        ans = min(ans, dp[abs(A - t)] + dp[abs(B - t)]);
    }
    printf("%d\n", ans);
    return 0;
}
