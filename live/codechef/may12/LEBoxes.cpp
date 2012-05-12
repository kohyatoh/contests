#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int N, M, V[32], C[32], D[32];
double P[32];
int dp[64][64];
vector<pair<int, double> > cs[32];
vector<double> sum[32];

double solve() {
    rep (i, 32) cs[i].clear();
    rep (i, 32) sum[i].clear();
    rep (i, 64) rep (j, 64) dp[i][j] = INT_MAX;
    rep (i, 64) dp[i][0] = 0;
    rep (k, M) {
        for (int i = 31; i >= 0; i--) {
            for (int j = 31; j >= 0; j--) if (dp[i][j] < INT_MAX) {
                dp[i+D[k]][j+1] = min(dp[i+D[k]][j+1], dp[i][j]+C[k]);
            }
        }
    }
    const int w = N/2, h = N-w;
    const int hh = 1<<h;
    rep (b, hh) {
        double p = 1;
        int a = 0, c = 0;
        rep (i, h) {
            if (b&(1<<i)) a += V[w+i], p *= P[w+i];
            else c++, p *= 1-P[w+i];
        }
        cs[c].push_back(mp(a, p));
    }
    rep (i, h+1) sort(cs[i].begin(), cs[i].end());
    rep (k, h+1) {
        sum[k].resize(cs[k].size()+1);
        sum[k][0] = 0;
        rep (i, cs[k].size()) sum[k][i+1] = sum[k][i] + cs[k][i].second;
    }
    const int ww = 1<<w;
    double ans = 0;
    rep (b, ww) {
        double p = 1;
        int a = 0, c = 0;
        rep (i, w) {
            if (b&(1<<i)) a += V[i], p *= P[i];
            else c++, p *= 1-P[i];
        }
        double s = 0;
        rep (k, h+1) {
            const int d = c + k;
            int u = cs[k].size();
            for (int x = M; x >= 0; x--) if (dp[d][x] < INT_MAX) {
                const int need = dp[d][x] - a;
                const int ix = lower_bound(cs[k].begin(), cs[k].begin()+u,
                        mp(need, -1.0)) - cs[k].begin();
                s += x * (sum[k][u] - sum[k][ix]);
                u = ix;
            }
        }
        ans += p * s;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        rep (i, N) {
            int p;
            scanf("%d%d", V+i, &p);
            P[i] = p / 100.0;
        }
        rep (i, M) scanf("%d%d", C+i, D+i);
        printf("%.4f\n", solve());
    }
    return 0;
}
