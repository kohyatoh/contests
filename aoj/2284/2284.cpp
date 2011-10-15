#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

typedef pair<int, int> P;
int diff(const P& a, const P& b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int w, h, f[128][128];
char buf[128];

int main() {
    for(;;) {
        scanf("%d%d", &w, &h);
        if(w==0 && h==0) return 0;
        memset(f, 0, sizeof(f));
        P g;
        rep(i, h) rep(j, w) {
            scanf("%s", buf);
            if(buf[0]=='S') f[i][j] = 1;
            else if(buf[0]=='G') g = mp(i, j);
            else if(isdigit(buf[0])) f[i][j] = atoi(buf)+1;
        }
        int m = 0;
        rep(i, h) rep(j, w) m = max(m, f[i][j]);
        vector<vector<P> > loc(m);
        vector<vector<int> > dp(m);
        rep(i, h) rep(j, w) if(f[i][j]) {
            loc[f[i][j]-1].push_back(mp(i, j));
            dp[f[i][j]-1].push_back(INF);
        }
        dp[0][0] = 0;
        rep(k, m-1) rep(i, dp[k].size()) rep(j, dp[k+1].size()) {
            cmin(dp[k+1][j], dp[k][i]+diff(loc[k+1][j], loc[k][i]));
        }
        int ans = INF;
        rep(i, dp[m-1].size()) cmin(ans, dp[m-1][i]+diff(loc[m-1][i], g));
        printf("%d\n", ans);
    }
}
