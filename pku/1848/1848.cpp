#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<20)

vector<int> g[128];
int dp[128][4];

void rec(int at, int pre) {
    vector<int> x, y, z;
    int s = 0;
    rep(i, g[at].size()) if(g[at][i]!=pre) {
        const int v = g[at][i];
        rec(v, at);
        s += dp[v][0];
        x.push_back(dp[v][0]);
        y.push_back(min(dp[v][1], dp[v][2]));
        z.push_back(dp[v][2]);
    }
    dp[at][1] = min(INF, s);
    dp[at][0] = dp[at][2] = INF;
    rep(k, x.size()) {
        dp[at][0] = min(dp[at][0], s-x[k]+z[k]+1);
        dp[at][2] = min(dp[at][2], s-x[k]+y[k]);
    }
    rep(i, x.size()) rep(j, i) {
        dp[at][0] = min(dp[at][0], s-x[i]+y[i]-x[j]+y[j]+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    rep(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rec(0, -1);
    printf("%d\n", dp[0][0]<INF ? dp[0][0] : -1);
    return 0;
}
