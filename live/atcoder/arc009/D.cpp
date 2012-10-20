#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;
#define MOD (1777777777LL)
#define INF (10000000LL)

struct unionset {
    int ud[16];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int index(const vector<int>& a, int x) {
    if (binary_search(a.begin(), a.end(), x) == false) return -1;
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int n, T, K;
vector<int> cid[100];
int g[100][8][8];
int ds[100][500];
Int dp[2][50000];

void build_ds(int n, int (*g)[8], int *ds) {
    if (n == 0) {
        ds[0] = 1;
        return ;
    }
    vector<pair<pair<int, int>, int> > es;
    rep (i, n) rep (j, i) if (g[i][j] != -1) {
        es.push_back(mp(mp(i, j), g[i][j]));
    }
    int comb = (1<<(n-1)) - 1;
    while (comb < (1<<es.size())) {
        us.init();
        int a = 0;
        rep (i, es.size()) if (comb & (1<<i)) {
            us.set(es[i].first.first, es[i].first.second);
            a += es[i].second;
        }
        if (us.size(0) == n) ds[a]++;
        int x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }
}

int main() {
    memset(g, -1, sizeof(g));
    scanf("%d%d%d", &n, &T, &K);
    rep (i, n) {
        int m, x;
        scanf("%d", &m);
        rep (_, m) {
            scanf("%d", &x);
            x--;
            cid[i].push_back(x);
        }
        sort(cid[i].begin(), cid[i].end());
    }
    int sum = 0;
    int M;
    scanf("%d", &M);
    rep (_, M) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        rep (i, n) {
            const int ai = index(cid[i], a);
            const int bi = index(cid[i], b);
            if (ai != -1 && bi != -1) g[i][ai][bi] = g[i][bi][ai] = c;
        }
        sum += c;
    }
    rep (k, n) build_ds(cid[k].size(), g[k], ds[k]);
    Int *cur = dp[0], *nxt = dp[1];
    cur[0] = 1;
    rep (k, n) {
        rep (i, 50000) nxt[i] = 0;
        rep (i, 50000) if (cur[i]) rep (j, 500) if (ds[k][j]) {
            nxt[i+j] += cur[i] * ds[k][j];
            if (nxt[i+j] > INF) nxt[i+j] = INF;
        }
        swap(cur, nxt);
    }
    int ans = -1;
    int rem = K;
    for (int i = 50000-1; i >= 0; i--) {
        if (cur[i] >= rem) { ans = sum - i; break; }
        rem -= cur[i];
    }
    printf("%d\n", ans);
    return 0;
}
