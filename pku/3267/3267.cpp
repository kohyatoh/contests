#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<30)

int n, m, L[800], dp[2][800][32];
char s[400], w[800][32];

int main() {
    scanf("%d%d", &m, &n);
    scanf("%s", s);
    rep(i, m) scanf("%s", w[i]);
    rep(i, m) L[i] = strlen(w[i]);
    int (*cur)[32]=dp[0], (*nxt)[32]=dp[1];
    rep(i, 800) rep(j, 32) cur[i][j] = INF;
    rep(i, m) cur[i][0] = 0;
    rep(k, n) {
        rep(i, m) rep(j, L[i]) nxt[i][j] = min(INF, cur[i][j]+1);
        rep(i, m) rep(j, L[i]) if(s[k]==w[i][j]) {
            if(j<L[i]-1) nxt[i][j+1] = min(nxt[i][j+1], cur[i][j]);
            else rep(x, m) nxt[x][0] = min(nxt[x][0], cur[i][j]);
        }
        swap(cur, nxt);
    }
    int ans = INF;
    rep(i, m) ans = min(ans, cur[i][0]);
    printf("%d\n", ans);
    return 0;
}
