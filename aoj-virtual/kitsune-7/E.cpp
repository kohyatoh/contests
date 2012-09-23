#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

Int dp[60], ans[60];

int main() {
    dp[0] = 1;
    for (int i = 1; i < 60; i++) {
        if (i >= 1) dp[i] += dp[i-1];
        if (i >= 2) dp[i] += 2*dp[i-2];
//        printf("[%d] = %lld\n", i, dp[i]);
    }
    rep (i, 60) if (i > 0) {
        if (i%2) ans[i] = (dp[i] + dp[i/2]) / 2;
        else ans[i] = (dp[i] + dp[i/2-1]*2 + dp[i/2]) / 2;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        cout << ans[n] << endl;
    }
    return 0;
}
