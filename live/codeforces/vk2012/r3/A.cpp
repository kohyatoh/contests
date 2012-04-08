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

#define N (200000)
int n, m, f[N], vis[2][N];
vector<int> g[2][N];

void draw(int a, int b, int *vis, const vector<int> *g) {
    vector<int> p[2];
    int cur = 0, nxt = 1;
    rep (i, n) if (f[i] == a) {
        vis[i] = 1;
        p[cur].push_back(i);
    }
    while (!p[cur].empty()) {
        rep (i, p[cur].size()) {
            const int at = p[cur][i];
            rep (j, g[at].size()) {
                const int to = g[at][j];
                if (!vis[to]) {
                    vis[to] = 1;
                    if (f[to] != b) p[nxt].push_back(to);
                }
            }
        }
        p[cur].clear();
        swap(cur, nxt);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) scanf("%d", f+i);
    rep (_, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[0][a].push_back(b);
        g[1][b].push_back(a);
    }
    draw(1, -1, vis[0], g[0]);
    draw(2, 1, vis[1], g[1]);
    rep (i, n) printf("%d\n", vis[0][i] && vis[1][i]);
    return 0;
}
