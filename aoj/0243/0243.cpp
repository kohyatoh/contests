#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int n, m;
char f[16][16];
int g[32][16][16];

bool completed(int (*g)[16]) {
    rep (i, n) rep (j, m) if (g[i][j] != g[0][0]) return false;
    return true;
}

void rec(int (*g)[16], int x, int y, int from, int to) {
    if (g[x][y] != from) return ;
    g[x][y] = to;
    if (x > 0) rec(g, x-1, y, from, to);
    if (x < n-1) rec(g, x+1, y, from, to);
    if (y > 0) rec(g, x, y-1, from, to);
    if (y < m-1) rec(g, x, y+1, from, to);
}

bool iddfs(int dep, int cur) {
    if (dep == cur) return completed(g[cur]);
    rep (k, 3) if (k != g[cur][0][0]) {
        rep (i, n) rep (j, m) g[cur+1][i][j] = g[cur][i][j];
        rec(g[cur+1], 0, 0, g[cur][0][0], k);
        if (iddfs(dep, cur+1)) return true;
    }
    return false;
}

int solve() {
    rep (i, n) rep(j, m) {
        if (f[i][j] == 'R') g[0][i][j] = 0;
        if (f[i][j] == 'G') g[0][i][j] = 1;
        if (f[i][j] == 'B') g[0][i][j] = 2;
    }
    rep (i, 32) if (iddfs(i, 0)) return i;
    assert(false);
    return -1;
}

int main() {
    for (;;) {
        scanf("%d%d", &m, &n);
        if (n == 0 && m == 0) return 0;
        rep (i, n) rep (j, m) scanf(" %c", f[i]+j);
        printf("%d\n", solve());
    }
}
