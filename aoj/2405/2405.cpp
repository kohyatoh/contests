#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define MOD (1000003LL)
typedef long long Int;

typedef pair<pair<int, int>, int> ST;
int n;
vector<int> g[60000];
map<ST, int> memo;
set<pair<int, int> > es;

void add(int p, int q) {
    if (p > q) swap(p, q);
    g[p].push_back(q);
    es.insert(mp(p, q));
}

Int rec(int p, int q, int x, int y) {
    if (p+1 == q) return x == y;
    const ST sig(mp(p, q), x*2+y);
    if (memo.count(sig)) return memo[sig];
    const int r = *(lower_bound(g[p].begin(), g[p].end(), q)-1);
    Int ans = 0;
    rep (k, 2) ans = (ans + rec(p, r, x, k) * rec(r, q, 1-k, y)) % MOD;
    if (x && y && es.count(mp(p, q))) {
        rep (k, 2) ans = (ans + rec(p, r, 0, k) * rec(r, q, 1-k, 0)) % MOD;
    }
    return memo[sig] = ans;
}

int main() {
    for (;;) {
        int m, a, b;
        scanf("%d%d", &n, &m);
        if (n == 0) return 0;
        rep (i, 60000) g[i].clear();
        es.clear();
        rep (_, m) {
            scanf("%d%d", &a, &b);
            add(a-1, b-1);
        }
        rep (i, n) add(i, (i+1)%n);
        rep (i, n) sort(g[i].begin(), g[i].end());
        memo.clear();
        printf("%d\n", (int)rec(0, n-1, 1, 1));
    }
}
