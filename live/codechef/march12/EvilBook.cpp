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

#define B (387420489LL)
int N, X, C[16], M[16];
vector<pair<Int, double> > dp[1024];

double solve() {
    rep (i, 1024) dp[i].clear();
    dp[0].push_back(mp(0LL, 0.0));
    const int nn = 1<<N;
    double ans = 1e100;
    rep (b, nn) {
        sort(dp[b].begin(), dp[b].end());
        Int pre = -1;
        rep (i, dp[b].size()) {
            const Int cm = dp[b][i].first;
            const double cc = dp[b][i].second;
            if (pre == cm) continue;
            pre = cm;
            if (cc >= ans) continue;
            rep (k, N) if (!(b&(1<<k))) {
                const int nb = b|(1<<k);
                double c = C[k];
                Int m = M[k]*B;
                for (Int x = 0; x <= cm && x < m; x+=X*B, c/=3, m/=3) {
                    const Int nm = cm+m-x;
                    const double nc = cc + c;
                    if (nc >= ans) continue;
                    if (nm >= 666*B) ans = min(ans, nc);
                    else dp[nb].push_back(mp(nm, nc));
                }
            }
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &X);
        rep (i, N) scanf("%d%d", C+i, M+i);
        Int s = 0;
        rep (i, N) s += M[i];
        if (s < 666) puts("impossible");
        else printf("%.0f\n", solve());
    }
    return 0;
}
