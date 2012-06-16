#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;
#define INF (1<<28)

int n, m, si, ti, p;
Int a[20000], b[20000];
vector<pair<int, int> > g[20000], h[20000];

void build(const vector<pair<int, int> > *g, Int *a, int si) {
    rep (i, n) a[i] = INF;
    priority_queue<pair<Int, int> > q;
    q.push(mp(0, si));
    while (!q.empty()) {
        const pair<Int, int> v = q.top();
        q.pop();
        const Int t = -v.first;
        const int at = v.second;
        if (a[at] < INF) continue;
        a[at] = t;
        rep (i, g[at].size()) {
            const int to = g[at][i].first;
            if (a[to] == INF) q.push(mp(-t-g[at][i].second, to));
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d%d%d%d%d", &n, &m, &si, &ti, &p);
        si--, ti--;
        rep (i, n) g[i].clear(), h[i].clear();
        rep (i, m) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            x--, y--;
            g[x].push_back(mp(y, c));
            h[y].push_back(mp(x, c));
        }
        build(g, a, si);
        build(h, b, ti);
        int ans = -1;
        rep (i, n) rep (j, g[i].size()) {
            if (a[i] + g[i][j].second + b[g[i][j].first] <= p) {
                ans = max(ans, g[i][j].second);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
