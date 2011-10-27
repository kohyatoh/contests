#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void cmax(int &a, int b) { if(a<b) a = b; }

int N, K, a[150], dp[150][2][256];
vector<int> g[150];

void rec(int at, int pre) {
    rep(i, K+1) dp[at][0][i] = dp[at][1][i] = 0;
    dp[at][0][0] = dp[at][1][0] = a[at];
    rep(i, g[at].size()) if(g[at][i]!=pre) {
        const int v = g[at][i];
        rec(v, at);
        for(int i=K; i>=0; i--) rep(j, K-i-1) {
            cmax(dp[at][1][i+j+2], dp[at][1][i]+dp[v][0][j]);
        }
        for(int i=K; i>=0; i--) rep(j, K-i) {
            cmax(dp[at][1][i+j+1], dp[at][0][i]+dp[v][1][j]);
        }
        for(int i=K; i>=0; i--) rep(j, K-i-1) {
            cmax(dp[at][0][i+j+2], dp[at][0][i]+dp[v][0][j]);
        }
    }
}

int main() {
    while(scanf("%d%d", &N, &K)!=EOF) {
        rep(i, N) g[i].clear();
        rep(i, N) scanf("%d", a+i);
        rep(i, N-1) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        rec(0, -1);
        int ans = 0;
        rep(i, K+1) cmax(ans, dp[0][0][i]);
        rep(i, K+1) cmax(ans, dp[0][1][i]);
        printf("%d\n", ans);
    }
    return 0;
}
