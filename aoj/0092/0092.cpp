#include <stdio.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int n, dp[1024][1024];
char f[1024][1024];

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) scanf("%s", f[i]);
        int ans = 0;
        rep (i, n) rep (j, n) {
            dp[i][j] = 0;
            if (f[i][j] == '.') {
                dp[i][j] = 1;
                if (i && j) {
                    const int a = min(dp[i-1][j-1],
                            min(dp[i][j-1], dp[i-1][j]));
                    dp[i][j] = a+1;
                }
            }
            ans = max(ans, dp[i][j]);
        }
        printf("%d\n", ans);
    }
}
