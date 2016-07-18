#include <stdio.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m, g[12][12];

int popcount(int b) {
    int c = 0;
    while (b) c++, b &= b-1;
    return c;
}

int main() {
    scanf("%d%d", &n, &m);
    rep (i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x-1][y-1] = g[y-1][x-1] = 1;
    }
    int ans = 0;
    rep (b, 1<<n) {
        int ok = 1;
        rep (i, n) if (b & (1<<i)) rep (j, i) if (b & (1<<j)) ok &= g[i][j];
        if (ok) ans = std::max(ans, popcount(b));
    }
    printf("%d\n", ans);
    return 0;
}
