#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define INF (1<<28)
typedef long long Int;

int N, B[64], C[64];
string A[64], D[64][64];
int g[64][64], vis[64];
int m, q[64];

void collect(int at) {
    if (vis[at]) return ;
    vis[at] = 1;
    q[m++] = at;
    rep (i, N) if (g[at][i]) collect(i);
}

int n, a, r[64], p[64];
Int f[64];

void prepare() {
    n = m;
    a = 0;
    rep (i, n) r[i] = q[i];
    rep (i, n) {
        p[i] = B[r[i]];
        f[i] = 0;
        rep (j, n) if (g[r[i]][r[j]]) f[i] |= 1LL<<j;
    }
}

void rec(int k, Int u) {
    int s = 0;
    rep (i, n) if (u&(1LL<<i)) s += p[i];
    if (s < a) return ;
    if (k == n) a = s;
    else {
        rep (i, k) if (!(u&(1LL<<i)) && !(f[i]&u)) return ;
        const int mask = (1LL<<n) - 1;
        if (u&(1LL<<k)) rec(k+1, u&(mask-f[k]));
        if (r[k]) rec(k+1, u&(mask-(1LL<<k)));
    }
}

int solve() {
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    rep (i, N) if (!vis[i]) {
        m = 0;
        collect(i);
        prepare();
        rec(0, (1LL<<n)-1);
        ans += a;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (;;) {
        cin >> N;
        if (N == 0) return 0;
        map<string, int> of;
        rep (i, N) {
            cin >> A[i] >> B[i] >> C[i];
            of[A[i]] = i;
            rep (j, C[i]) cin >> D[i][j];
        }
        memset(g, 0, sizeof(g));
        rep (i, N) rep (j, C[i]) g[i][of[D[i][j]]] = 1;
        printf("%d\n", solve());
    }
}
