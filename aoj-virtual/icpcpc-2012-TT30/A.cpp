#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define INF (1<<28)

int n, m, a[1024];
vector<int> g[1024];

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        if (_q) puts("");
        scanf("%d%d", &n, &m);
        rep (i, n) a[i] = INF;
        rep (i, n) g[i].clear();
        rep (i, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        queue<pair<int, int> > q;
        q.push(mp(0, 0));
        while (!q.empty()) {
            const pair<int, int> v = q.front();
            q.pop();
            const int t = v.first;
            const int at = v.second;
            if (a[at] < INF) continue;
            a[at] = t;
            rep (i, g[at].size()) q.push(mp(t+1, g[at][i]));
        }
        rep (i, n-1) printf("%d\n", a[i+1]);
    }
    return 0;
}
