#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

int N, M, Q;
vector<pair<int, Int> > g[200000];
Int hi[200000], cy[64];
bool vis[200000];

void add(Int b) {
    for (int x = 63; b; x--) if (b&(1LL<<x)) {
        if (cy[x] == 0) { cy[x] = b; return ; }
        b ^= cy[x];
    }
}

void rec(int at, int pre, Int bit) {
    if (vis[at]) {
        add(bit^hi[at]);
        return ;
    }
    vis[at] = 1;
    hi[at] = bit;
    rep (i, g[at].size()) {
        const int to = g[at][i].first;
        if (to == pre) continue;
        rec(to, at, bit^g[at][i].second);
    }
}

void build() {
    rec(0, -1, 0);
}

Int solve(int u, int v) {
    Int ans = hi[u]^hi[v];
    for (int x = 63; x >= 0; x--) if (!(ans&(1LL<<x))) ans ^= cy[x];
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> Q;
    rep (i, M) {
        int f, t;
        Int p;
        cin >> f >> t >> p;
        g[f].push_back(mp(t, p));
        g[t].push_back(mp(f, p));
    }
    build();
    rep (_, Q) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
