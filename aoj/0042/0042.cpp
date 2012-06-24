#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int W, n, dp[1024];

int main() {
    for (int _q = 0;; _q++) {
        scanf("%d", &W);
        if (W == 0) return 0;
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        rep (i, n) {
            int v, w;
            scanf("%d,%d", &v, &w);
            for (int i = W-w; i >= 0; i--) {
                dp[i+w] = max(dp[i+w], dp[i]+v);
            }
        }
        int ansv = 0, answ = 0;
        rep (i, W+1) if (ansv < dp[i]) {
            ansv = dp[i];
            answ = i;
        }
        printf("Case %d:\n", _q+1);
        printf("%d\n", ansv);
        printf("%d\n", answ);
    }
}
