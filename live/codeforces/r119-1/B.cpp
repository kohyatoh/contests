#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<28)
#define MOD (YOUR_MODULUS)
inline void cmin(int &a, int b) { if (a > b) a = b; }

int n, m, r, g[64][64][64], dp[64][64][64], mg[64][64];

int main() {
    rep (i, 64) rep (j, 64) rep (k, 64) g[i][j][k] = INF;
    rep (i, 64) rep (j, 64) rep (k, 64) dp[i][j][k] = INF;
    rep (i, 64) rep (j, 64) mg[i][j] = INF;
    scanf("%d%d%d", &n, &m, &r);
    rep (q, m) rep (i, n) rep (j, n) scanf("%d", g[q][i]+j);
    rep (q, m) rep (k, n) rep (i, n) rep (j, n) {
        cmin(g[q][i][j], g[q][i][k]+g[q][k][j]);
    }
    rep (q, m) rep (i, n) rep (j, n) {
        cmin(mg[i][j], g[q][i][j]);
    }
    rep (s, n) {
        rep (i, n) cmin(dp[s][0][i], mg[s][i]);
        rep (x, 63) {
            rep (i, n) rep (j, n) {
                cmin(dp[s][x+1][j], dp[s][x][i]+mg[i][j]);
            }
        }
    }
    rep (_, r) {
        int s, t, k;
        scanf("%d%d%d", &s, &t, &k);
        s--, t--;
        if (k > 61) k = 61;
        printf("%d\n", dp[s][k][t]);
    }
    return 0;
}
