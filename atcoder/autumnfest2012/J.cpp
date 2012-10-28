#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (1000003)
typedef long long Int;
inline void add(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }

int H, T, dp[80][80][80];
Int inv[80], ift[80];

Int C(int n, int k) {
    Int a = ift[k];
    rep (i, k) a = a*(n-i)%MOD;
    return a;
}

int main() {
    inv[1] = 1;
    for (int i = 2; i < 80; i++) inv[i] = inv[MOD%i] * (MOD - MOD/i) % MOD;
    ift[0] = 1;
    rep (i, 80-1) ift[i+1] = inv[i+1]*ift[i]%MOD;
    scanf("%d%d", &H, &T);
    dp[0][0][0] = 1;
    rep (i, 80-1) rep (j, 80) rep (k, 80) if (dp[i][j][k]) {
        for (int x = 2, y = 1; ; x++) {
            while ((y+1)*(y+1) <= x) y++;
            if (j+y >= 80 || k+x-y >= 80) break;
            add(dp[i+1][j+y][k+x-y], dp[i][j][k]);
        }
    }
    int ans = 0;
    rep (i, 80) rep (j, 80) if (j <= T) {
        int s = 0;
        rep (k, H) add(s, dp[i][j][k]);
        if (s) add(ans, C(T-j+i+1, i+1)*s%MOD);
    }
    printf("%d\n", ans);
    return 0;
}
