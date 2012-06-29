#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char f[16][16], g[16][16];

void rec(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return ;
    if (g[x][y]) return;
    g[x][y] = 1;
    if (f[x][y] == '1') {
        rep (i, 3) rec(x+1+i, y), rec(x, y+1+i), rec(x-1-i, y), rec(x, y-1-i);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        rep (i, 8) scanf("%s", f[i]);
        int x, y;
        scanf("%d%d", &y, &x);
        x--, y--;
        memset(g, 0, sizeof(g));
        rec(x, y);
        printf("Data %d:\n", _q+1);
        rep (i, 8) {
            rep (j, 8) putchar(f[i][j]=='1' && g[i][j]==0 ? '1' : '0');
            putchar('\n');
        }
    }
    return 0;
}
