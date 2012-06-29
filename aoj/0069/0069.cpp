#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m, sx, gx;
char f[32][16];

int simulate(int h, int x) {
    while (h < m) {
        if (x > 0 && f[h][x-1] == '1') x--;
        else if (x < n-1 && f[h][x] == '1') x++;
        h++;
    }
    return x;
}

void solve() {
    if (simulate(0, sx) == gx) {
        printf("%d\n", 0);
        return ;
    }
    int x = sx;
    rep (i, m) {
        if ((x == 0 || f[i][x-1] != '1') && (x == n-1 || f[i][x] != '1')) {
            if (x-1 >= 0 && (x-1 == 0 || f[i][x-2] != '1')) {
                if (simulate(i+1, x-1) == gx) {
                    printf("%d %d\n", i+1, x);
                    return ;
                }
            }
            if (x+1 < n && (x+1 == n-1 || f[i][x+1] != '1')) {
                if (simulate(i+1, x+1) == gx) {
                    printf("%d %d\n", i+1, x+1);
                    return ;
                }
            }
        }
        if (x > 0 && f[i][x-1] == '1') x--;
        else if (x < n-1 && f[i][x] == '1') x++;
    }
    printf("%d\n", 1);
}

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        scanf("%d%d%d", &sx, &gx, &m);
        sx--, gx--;
        rep (i, m) scanf("%s", f[i]);
        solve();
    }
    return 0;
}
