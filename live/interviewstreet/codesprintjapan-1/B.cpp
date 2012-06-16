#include <stdio.h>
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

int N, K, is[120000];
Int dp[120000][2];
vector<pair<int, int> > g[120000];

void rec(int at, int pre) {
    int x = 0, y = 1;
    Int sub[2][2];
    sub[x][0] = sub[x][1] = 0;
    if (is[at]) sub[x][0] = INF;
    rep (i, g[at].size()) if (g[at][i].first != pre) {
        const int to = g[at][i].first;
        const int w = g[at][i].second;
        rec(to, at);
        sub[y][0] = sub[y][1] = INF;
        rep (a, 2) rep (b, 2) {
            if (a+b < 2) cmin(sub[y][a+b], sub[x][a]+dp[to][b]);
            cmin(sub[y][a], sub[x][a]+dp[to][b]+w);
        }
        swap(x, y);
    }
    rep (i, 2) dp[at][i] = sub[x][i];
}

int main() {
    scanf("%d%d", &N, &K);
    rep (i, N-1) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(mp(y, z));
        g[y].push_back(mp(x, z));
    }
    rep (i, K) {
        int x;
        scanf("%d", &x);
        is[x] = 1;
    }
    rec(0, -1);
    cout << min(dp[0][0], dp[0][1]) << endl;
    return 0;
}
