#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, dp[300][2], mul[300][2];
vector<int> g[300];

void rec(int at) {
    rep(i, g[at].size()) rec(g[at][i]);
    rep(k, 2) {
        dp[at][k] = k;
        mul[at][k] = 0;
        rep(i, g[at].size()) {
            const int v = g[at][i];
            dp[at][k] += dp[v][k^1];
            mul[at][k] |= mul[v][k^1];
        }
    }
    if(dp[at][0]==dp[at][1]) mul[at][1] = 1;
    if(dp[at][1]<dp[at][0]) {
        dp[at][1] = dp[at][0];
        mul[at][1] = mul[at][0];
    }
}

char name[300][128], boss[300][128];

int main() {
    for(;;) {
        rep(i, 300) g[i].clear();
        scanf("%d", &n);
        if(n==0) return 0;
        scanf(" %s", name[0]);
        for(int i=1; i<n; i++) scanf(" %s%s", name[i], boss[i]);
        map<string, int> id;
        rep(i, n) id[name[i]] = i;
        for(int i=1; i<n; i++) g[id[boss[i]]].push_back(i);
        rec(0);
        printf("%d %s\n", dp[0][1], !mul[0][1] ? "Yes" : "No");
    }
}
