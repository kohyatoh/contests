#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m, a[200000], dp[2], sub[200000];

int main() {
    for (;;) {
        scanf("%d%d", &m, &n);
        if (m == 0 && n == 0) return 0;
        int ans = 0, cur = 0, nxt = 1;
        dp[cur] = dp[nxt] = 0;
        rep (_, m) {
            rep (i, n) scanf("%d", a+i);
            rep (i, n) {
                const int pre = i ? sub[i-1] : 0;
                sub[i+1] = max(sub[i], pre+a[i]);
            }
            dp[nxt] = max(dp[cur], dp[nxt]+sub[n]);
            swap(cur, nxt);
        }
        printf("%d\n", dp[cur]);
    }
}
