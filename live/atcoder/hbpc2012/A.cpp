#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int m, n, a[400*400], b[400*400];
vector<int> g[400];
int vis[50000];

int main() {
    scanf("%d%d", &m, &n);
    rep (i, m) scanf("%d%d", a+i, b+i);
    rep (k, 321) {
        rep (i, m) if (a[i] <= k) g[k].push_back(b[i]-a[i]);
        sort(g[k].begin(), g[k].end());
        g[k].erase(unique(g[k].begin(), g[k].end()), g[k].end());
    }
    queue<pair<int, int> > q;
    q.push(mp(1, 1));
    while (!q.empty()) {
        const pair<int, int> vv = q.front();
        q.pop();
        const int t = vv.first;
        const int at = vv.second;
        if (vis[at]) continue;
        vis[at] = 1;
        if (at == n) {
            printf("%d\n", t);
            return 0;
        }
        const int z = min(at, 320);
        rep (i, g[z].size()) {
            const int to = at + g[z][i];
            if (to >= 50000) continue;
            if (!vis[to]) q.push(mp(t+1, to));
        }
    }
    printf("%d\n", -1);
    return 0;
}
