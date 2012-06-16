#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;
#define INF (1LL<<60)
inline void cmin(Int &a, Int b) { if (a > b) a = b; }

int N;
pair<int, int> is[1024];
int a[1024], dp[1024][1024];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        rep (i, N) scanf("%d%d", &is[i].first, &is[i].second);
        sort(is, is+N);
        rep (i, N) a[i] = lower_bound(is, is+N, mp(is[i].second+1, -1)) - is;
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = N-1; i >= 0; i--) for (int j = N; j > i; j--) {
            dp[i][j] = dp[min(a[i], j)][max(a[i], j)]+1;
            dp[i][j] = max(dp[i][j], dp[i+1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j+1]);
            ans = max(ans, dp[i][j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
