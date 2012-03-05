#include <stdio.h>
#include <string.h>
#include <assert.h>
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
int base[16];
vector<Int> MF[16];
vector<double> CF[16];
vector<pair<Int, double> > dp[1024];

double solve() {
    rep (k, N) {
        MF[k].clear();
        CF[k].clear();
        Int m = M[k]*B;
        double c = C[k];
        for (Int x = 0; x < m; x += X*B) {
            MF[k].push_back(m-x);
            CF[k].push_back(c);
            m /= 3;
            c /= 3;
        }
        int b = 0;
        while (b < (int)MF[k].size() && MF[k][b] >= 666*B) b++;
        base[k] = b;
        assert(MF[k].size() - base[k] <= 3);
    }
    rep (b, 1024) rep (i, dp[b].size()) dp[b][i] = mp(-1LL, 1e100);
    dp[0][0] = mp(0LL, 0.0);
    const int nn = 1<<N;
    double ans = 1e100;
    rep (b, nn) rep (i, dp[b].size()) {
        const Int cm = dp[b][i].first;
        const double cc = dp[b][i].second;
        if (cc > ans) continue;
        const int mx = cm / (X*B);
        int mask = 1;
        if (cm == -1) continue;
        rep (k, N) {
            if (!(b&(1<<k))) {
                const int nb = b|(1<<k);
                const int nmm = (i-i%mask)*3 + i%mask;
                if (base[k] != 0) {
                    const int ix = min(base[k]-1, mx);
                    ans = min(ans, cc+CF[k][ix]);
                }
                const int end = min(mx, (int)MF[k].size()-1);
                for (int j = end; j >= base[k]; j--) {
                    const Int nm = cm + MF[k][j];
                    const double nc = cc + CF[k][j];
                    if (nc > ans) break;
                    if (nm >= 666*B) {
                        ans = nc;
                        break;
                    }
                    else {
                        const int ni = nmm + (j-base[k])*mask;
                        dp[nb][ni].first = nm;
                        dp[nb][ni].second = nc;
                    }
                }
            }
            else {
                mask *= 3;
            }
        }
    }
    return ans;
}

int main() {
    rep (i, 1024) {
        int k = i, c = 1;
        while (k) k &= k-1, c *= 3;
        dp[i].resize(c);
    }
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
