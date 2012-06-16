#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

Int dp[32][32];

Int way(int n, int *a, int k) {
    if (k > n) return 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep (i, n) rep (j, a[i]+1) {
        dp[i+1][j] += dp[i][j];
        dp[i+1][j+1] += (a[i]-j)*dp[i][j];
    }
    return dp[n][k];
}

Int solve(int n, int k) {
    static int a[32], b[32];
    rep (i, n) a[i] = 1 + i/2*2;
    rep (i, n-1) b[i] = 2 + i/2*2;
    Int ans = 0;
    rep (i, k+1) ans += way(n, a, i) * way(n-1, b, k-i);
    return ans;
}

int main() {
    for (;;) {
        int n, k;
        cin >> n >> k;
        if (n == 0) return 0;
        cout << solve(n, k) << endl;
    }
}
