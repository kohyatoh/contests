#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int n, vis[256], rk[256];
map<string, int> dict;
vector<pair<int, int> > g[256];

int of(const string& s) {
    if (dict.count(s) == 0) dict[s] = n++;
    return dict[s];
}

bool visit(int at, int r) {
    if (vis[at]) return rk[at] == r;
    vis[at] = 1;
    rk[at] = r;
    rep (i, g[at].size()) {
        if (!visit(g[at][i].first, r+g[at][i].second)) return false;
    }
    return true;
}

int main() {
    for (;;) {
        int m;
        scanf("%d", &m);
        if (m == 0) return 0;
        n = 0;
        dict.clear();
        rep (i, 256) g[i].clear();
        rep (_, m) {
            static char a[32], b[32];
            int x;
            scanf(" 1 %s = 10^%d %s", a, &x, b);
            const int u = of(a);
            const int v = of(b);
            g[u].push_back(mp(v, -x));
            g[v].push_back(mp(u, x));
        }
        rep (i, n) vis[i] = 0;
        bool ans = true;
        rep (i, n) if (!vis[i]) {
            if (!visit(i, 0)) ans = false;
        }
        puts(ans ? "Yes" : "No");
    }
}
