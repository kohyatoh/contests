#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char f[16][16];

void draw(int x, int y) {
    if (x < 0 || x >= 12 || y < 0 || y >= 12) return ;
    if (f[x][y] != '1') return ;
    f[x][y] = '0';
    rep (d, 4) draw(x+dx[d], y+dy[d]);
}

int main() {
    while (scanf("%s", f[0]) != EOF) {
        rep (i, 11) scanf("%s", f[i+1]);
        int ans = 0;
        rep (i, 12) rep (j, 12) if (f[i][j] == '1') draw(i, j), ans++;
        printf("%d\n", ans);
    }
    return 0;
}
