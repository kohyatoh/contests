#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int n, d[20000], L[20000], D;
int dp[20000];

bool solve() {
    d[n] = D;
    dp[n] = -1;
    dp[0] = min(d[0], L[0]);
    int i = 1;
    rep (k, n) {
        dp[k] = min(dp[k], L[k]);
        const Int cur = (Int)dp[k]*dp[k];
        if (dp[k] == 0) return false;
        while (i <= n) {
            const Int di = (Int)(d[i]-d[k])*(d[i]-d[k]);
            if (cur < di) break;
            dp[i] = d[i]-d[k];
            i++;
        }
    }
    return dp[n] >= 0;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        rep (i, n) scanf("%d%d", d+i, L+i);
        scanf("%d", &D);
        printf("Case #%d: %s\n", _q+1, solve() ? "YES" : "NO");
    }
    return 0;
}
