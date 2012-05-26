#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
typedef long long Int;
#define INF (1LL<<60)

int n, L, C, t[2000], sum[2000];
pair<Int, Int> dp[2000];

pair<Int, Int> solve() {
    rep (i, 2000) dp[i] = mp(INF, INF);
    rep (i, n) sum[i+1] = sum[i] + t[i];
    dp[0] = mp(0, 0);
    rep (i, n) {
        for (int j = 0; j <= i; j++) {
            const int mt = sum[i+1] - sum[j];
            if (mt <= L) {
                Int di = 0;
                if (L-mt <= 10 && L-mt > 0) di = -C;
                if (L-mt > 10) di = (L-mt-10LL)*(L-mt-10LL);
                dp[i+1] = min(dp[i+1], mp(dp[j].fst+1, dp[j].snd+di));
            }
        }
    }
    return dp[n];
}

int main() {
    for (int _q = 0;; _q++) {
        scanf("%d", &n);
        if (n == 0) return 0;
        scanf("%d%d", &L, &C);
        rep (i, n) scanf("%d", t+i);
        pair<int, int> ans = solve();
        if (_q) cout << endl;
        cout << "Case " << _q+1 << ":" << endl;
        cout << "Minimum number of lectures: " << ans.fst << endl;
        cout << "Total dissatisfaction index: " << ans.snd << endl;

    }
    return 0;
}
