#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline void cmax(int &a, int b) { if (a < b) a = b; }

char p[4000];
int dp[2][32][32];

int solve() {
    const int n = strlen(p);
    memset(dp, 0, sizeof(dp));
    int (*cur)[32] = dp[0], (*nxt)[32] = dp[1];
    rep (k, n) {
        memcpy(nxt, cur, sizeof(dp[0]));
        const int ix = p[k] - 'a';
        rep (i, 26) {
            rep (j, ix+1) {
                cmax(nxt[ix][i], cur[j][i]+1);
            }
            for (int j = ix; j < 26; j++) {
                cmax(nxt[i][ix], cur[i][j]+1);
            }
        }
        std::swap(cur, nxt);
    }
    int ans = 0;
    rep (i, 26) rep (j, 26) cmax(ans, cur[i][j]);
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s", p);
        printf("%d\n", solve());
    }
    return 0;
}
