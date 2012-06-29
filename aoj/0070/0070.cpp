#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int bitcount(int a) {
    int c = 0;
    while (a) c++, a&=a-1;
    return c;
}

int dp[1<<10][400], ans[16][400];

int main() {
    dp[0][0] = 1;
    rep (b, 1<<10) {
        const int c = bitcount(b);
        rep (i, 10) if (!(b&(1<<i))) {
            rep (s, 400) if (dp[b][s]) {
                dp[b|(1<<i)][s+(c+1)*i] += dp[b][s];
            }
        }
        rep (s, 400) if (dp[b][s]) ans[c][s] += dp[b][s];
    }
    int n, s;
    while (scanf("%d%d", &n, &s) != EOF) {
        printf("%d\n", n < 16 && s < 400 ? ans[n][s] : 0);
    }
    return 0;
}
