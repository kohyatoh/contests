#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct item {
    int w, f, c;
    item(int w, int f, int c) : w(w), f(f), c(c) {}
};

int L, n, B, dp[2000][2000];
vector<item> a[2000];

int main() {
    scanf("%d%d%d", &L, &n, &B);
    rep(i, n) {
        int x, w, f, c;
        scanf("%d%d%d%d", &x, &w, &f, &c);
        a[x].push_back(item(w, f, c));
    }
    rep(i, 2000) rep(j, 2000) dp[i][j] = -(1<<30);
    dp[0][0] = 0;
    rep(i, L) rep(j, B) if(dp[i][j]>=0) rep(k, a[i].size()) {
        const int nx = i+a[i][k].w;
        const int nc = j+a[i][k].c;
        if(nc>B) continue;
        dp[nx][nc] = max(dp[nx][nc], dp[i][j]+a[i][k].f);
    }
    int ans = -1;
    rep(i, B+1) ans = max(ans, dp[L][i]);
    printf("%d\n", ans);
    return 0;
}
