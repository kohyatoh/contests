#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (1000003LL)
typedef long long Int;

int n, mi, memo[60000*4], cs[60000][2];
vector<int> g[60000];
bool has[60000];

void add(int p, int q) {
    if (p > q) swap(p, q);
    g[p].push_back(q);
}

int pre(int p, int q) {
    if (p+1 == q) return -1;
    const int k = mi++;
    has[k] = false;
    if (g[p].back() == q) {
        has[k] = true;
        g[p].pop_back();
    }
    const int r = g[p].back();
    rep (b, 4) memo[k*4|b] = -1;
    cs[k][0] = pre(p, r);
    cs[k][1] = pre(r, q);
    return k;
}

int rec(int k, int x, int y) {
    if (k == -1) return x == y;
    const int sig = k*4|x*2|y;
    if (memo[sig] != -1) return memo[sig];
    const int p = cs[k][0], q = cs[k][1];
    Int ans = 0;
    rep (i, 2) ans = (ans + (Int)rec(p, x, i)*rec(q, 1-i, y)) % MOD;
    if (x && y && has[k]) {
        rep (i, 2) ans = (ans + (Int)rec(p, 0, i)*rec(q, 1-i, 0)) % MOD;
    }
    return memo[sig] = ans;
}

int main() {
    for (;;) {
        int m, a, b;
        scanf("%d%d", &n, &m);
        if (n == 0) return 0;
        rep (i, 60000) g[i].clear();
        rep (_, m) {
            scanf("%d%d", &a, &b);
            add(a-1, b-1);
        }
        rep (i, n) add(i, (i+1)%n);
        rep (i, n) sort(g[i].begin(), g[i].end());
        mi = 0;
        pre(0, n-1);
        printf("%d\n", (int)rec(0, 1, 1));
    }
}
