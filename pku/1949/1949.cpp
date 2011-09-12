#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int n, dp[20000];

int main() {
    scanf("%d", &n);
    int ans=0;
    rep(i, n) {
        int c, m, k;
        scanf("%d%d", &c, &m);
        dp[i] = c;
        rep(j, m) {
            scanf("%d", &k);
            dp[i] = max(dp[i], dp[k-1]+c);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}

