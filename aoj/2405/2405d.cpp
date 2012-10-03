#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (1000003LL)
typedef long long Int;

int n, mi, cs[60000][2], dp[60000][2][2];
vector<int> g[60000];
bool has[60000];

inline int f(int k, int x, int y) { return k == -1 ? x==y : dp[k][x][y]; }

void add(int p, int q) {
    if (p > q) swap(p, q);
    g[p].push_back(q);
}

int pre(int p, int q) {
    if (p+1 == q) return -1;
    const int k = mi++;
    has[k] = 0;
    if (g[p].back() == q) has[k] = 1, g[p].pop_back();
    const int r = g[p].back();
    cs[k][0] = pre(p, r);
    cs[k][1] = pre(r, q);
    return k;
}

int main() {
    for (;;) {
        int m, a, b;
        scanf("%d%d", &n, &m);
        if (n == 0) return 0;
        rep (_, m) {
            scanf("%d%d", &a, &b);
            add(a-1, b-1);
        }
        rep (i, n) add(i, (i+1)%n);
        rep (i, n) sort(g[i].begin(), g[i].end());
        mi = 0;
        pre(0, n-1);
        for (int k = mi-1; k >= 0; k--) {
            const int p = cs[k][0], q = cs[k][1];
#define F(x, y) ((Int)f(p, x, 0)*f(q, 1, y) + (Int)f(p, x, 1)*f(q, 0, y))
            dp[k][0][0] = F(0, 0) % MOD;
            dp[k][0][1] = F(0, 1) % MOD;
            dp[k][1][0] = F(1, 0) % MOD;
            Int a = F(1, 1);
            if (has[k]) a += dp[k][0][0];
            dp[k][1][1] = a % MOD;
        }
        printf("%d\n", dp[0][1][1]);
    }
}
