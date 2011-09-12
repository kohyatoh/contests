#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, dp[20000];
pair<int, int> a[20000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) break;
        rep(i, n) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a, a+n);
        rep(i, 20000) dp[i] = 300;
        dp[0] = 0;
        rep(i, n) *upper_bound(dp, dp+n, a[i].second) = a[i].second;
        int ans = 0;
        rep(i, 20000) if(dp[i]<300) ans = i;
        printf("%d\n", ans);
    }
    puts("*");
    return 0;
}
