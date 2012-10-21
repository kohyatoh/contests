#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, M;
char f[128][128];
bool is[128][128], vis[128][128];

void visit(int x, int y, char c) {
    if (f[x][y] != c || !is[x][y]) return ;
    if (vis[x][y]) return ;
    vis[x][y] = true;
    if (x) visit(x-1, y, c);
    if (y) visit(x, y-1, c);
    visit(x+1, y, c);
    visit(x, y+1, c);
}

int main() {
    scanf("%d%d", &N, &M);
    rep (i, N) rep (j, M) scanf(" %c", f[i]+j);
    rep (i, N) rep (j, M-2) {
        bool ok = true;
        rep (k, 3) if (f[i][j] != f[i][j+k]) ok = false;
        if (ok) rep (k, 3) is[i][j+k] = true;
    }
    rep (i, N-2) rep (j, M) {
        bool ok = true;
        rep (k, 3) if (f[i][j] != f[i+k][j]) ok = false;
        if (ok) rep (k, 3) is[i+k][j] = true;
    }
    int ans = 0;
    rep (i, N) rep (j, M) {
        if (!vis[i][j] && is[i][j]) visit(i, j, f[i][j]), ans++;
    }
    printf("%d\n", ans);
    return 0;
}
