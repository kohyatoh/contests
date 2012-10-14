#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define INF (1<<28)
inline void cmin(int &a, int b) { if (a > b) a = b; }

int N, M;
pair<int, int> ps[128];
int dp[128];

int main() {
    scanf("%d%d", &N, &M);
    rep (i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        ps[i] = mp(x-1, y-1);
    }
    sort(ps, ps+M);
    rep (i, 128) dp[i] = INF;
    dp[0] = 0;
    rep (k, M) {
        for (int i = ps[k].first; i < N; i++) {
            cmin(dp[ps[k].second+1], dp[i] + 1);
        }
    }
    if (dp[N] == INF) puts("Impossible");
    else printf("%d\n", dp[N]);
    return 0;
}
