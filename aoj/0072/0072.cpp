#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int n, m, vis[128];
vector<pair<int, int> > g[128];

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) g[i].clear();
        scanf("%d", &m);
        rep (i, m) {
            int a, b, c;
            scanf("%d,%d,%d", &a, &b, &c);
            g[a].push_back(mp(-(c/100-1), b));
            g[b].push_back(mp(-(c/100-1), a));
        }
        memset(vis, 0, sizeof(vis));
        priority_queue<pair<int, int> > q;
        q.push(mp(0, 0));
        int ans = 0;
        while (!q.empty()) {
            const pair<int, int> vv(q.top());
            q.pop();
            const int x = vv.second;
            if (vis[x]) continue;
            vis[x] = 1;
            ans += -vv.first;
            rep (i, g[x].size()) q.push(g[x][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
