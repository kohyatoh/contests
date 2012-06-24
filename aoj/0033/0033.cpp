#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[10], dp[16][16];

bool can() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep (i, 10) {
        rep (j, 11) if (dp[i][j]) {
            const int pre = i == 0 ? 0 : a[i-1];
            if (a[i] > j) dp[i+1][pre] = 1;
            if (a[i] > pre) dp[i+1][j] = 1;
        }
    }
    rep (i, 11) if (dp[10][i]) return true;
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        rep (i, 10) scanf("%d", a+i);
        puts(can() ? "YES" : "NO");
    }
    return 0;
}
