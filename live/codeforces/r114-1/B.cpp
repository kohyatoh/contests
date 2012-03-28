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
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

int N, L, K;
double dp[2][256][512], p[256];
int a[256];

int main() {
    scanf("%d%d%d", &N, &L, &K);
    rep (i, N) {
        int w;
        scanf("%d", &w);
        p[i] = w / 100.0;
    }
    rep (i, N) scanf("%d", a+i);
    double (*cur)[512] = dp[0], (*nxt)[512] = dp[1];
    cur[0][min(511, 256+K)] = 1.0;
    rep (k, N) {
        memset(nxt, 0, sizeof(dp[0]));
        rep (i, 210) rep (j, 512) if (cur[i][j]) {
            if (a[k] == -1) {
                nxt[i+1][j-1] += p[k] * cur[i][j];
            }
            else {
                nxt[i+1][min(511, j+a[k])] += p[k] * cur[i][j];
            }
            nxt[i][j] += (1-p[k]) * cur[i][j];
        }
        swap(cur, nxt);
    }
    double ans = 0;
    rep (i, 256) rep (j, 512) if (i >= L && j >= 256) ans += cur[i][j];
    printf("%.9f\n", ans);
    return 0;
}
