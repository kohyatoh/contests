#include <stdio.h>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define foreach(it, c) for(__typeof(c.begin()) it=c.begin(); it!=c.end(); it++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int f[5][5];
set<int> dp[6][5][5];

int main() {
    rep(i, 5) rep(j, 5) {
        scanf("%d", f[i]+j);
        dp[0][i][j].insert(f[i][j]);
    }
    rep(k, 5) rep(i, 5) rep(j, 5) {
        foreach(it, dp[k][i][j]) rep(d, 4) {
            const int nx=i+dx[d], ny=j+dy[d];
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            dp[k+1][nx][ny].insert(*it*10+f[nx][ny]);
        }
    }
    set<int> ans;
    rep(i, 5) rep(j, 5) ans.insert(dp[5][i][j].begin(), dp[5][i][j].end());
    printf("%u\n", ans.size());
    return 0;
}

