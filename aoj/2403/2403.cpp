#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define INF (1<<28)

int N, B[64], C[64];
string A[64], D[64][64];
int g[64][64], cf[64], ct[64];
int dp[1<<20];

int solve() {
    const int n = N / 2, m = N - n;
    const int nn = 1<<n, mm = 1<<m;
    memset(cf, 0, sizeof(cf));
    memset(ct, 0, sizeof(ct));
    rep (i, n) rep (j, n) if (g[i][j]) cf[i] |= 1<<j;
    rep (i, m) rep (j, m) if (g[i+n][j+n]) cf[i+n] |= 1<<j;
    rep (i, m) rep (j, n) if (g[i+n][j]) ct[i] |= 1<<j;
    rep (i, nn) dp[i] = -INF;
    rep (b, nn) {
        if (b&1) {
            bool ok = true;
            rep (i, n) if (b&(1<<i) && b&cf[i]) { ok = false; break; }
            if (ok) {
                int s = 0;
                rep (i, n) if (b&(1<<i)) s += B[i];
                dp[b] = max(dp[b], s);
            }
        }
        rep (i, n) dp[b|(1<<i)] = max(dp[b|(1<<i)], dp[b]);
    }
    int ans = 0;
    rep (b, mm) {
        bool ok = true;
        rep (i, m) if (b&(1<<i) && b&cf[i+n]) { ok = false; break; }
        if (!ok) continue;
        int s = 0, z = 0;
        rep (i, m) if (b&(1<<i)) s += B[i+n], z |= ct[i];
        ans = max(ans, dp[nn-1-z] + s);
    }
    return ans;
}

int main() {
    for (;;) {
        cin >> N;
        if (N == 0) return 0;
        map<string, int> of;
        rep (i, N) {
            cin >> A[i] >> B[i] >> C[i];
            of[A[i]] = i;
            rep (j, C[i]) cin >> D[i][j];
        }
        memset(g, 0, sizeof(g));
        rep (i, N) rep (j, C[i]) g[i][of[D[i][j]]] = 1;
        printf("%d\n", solve());
    }
}
