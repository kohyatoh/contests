#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
#define mp make_pair

#define B (400)
int n, m, a[220], b[220], dp[220][22][900];
pair<int, int> pre[220][22][900];

int main() {
    for(int _q=0;; _q++) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) scanf("%d%d", a+i, b+i);
        rep(i, 220) rep(j, 22) rep(k, 900) dp[i][j][k] = -INF;
        dp[0][0][B] = 0;
        rep(i, n) rep(j, m+1) rep(k, 900) if(dp[i][j][k]>=0) {
            if(dp[i+1][j][k]<dp[i][j][k]) {
                dp[i+1][j][k] = dp[i][j][k];
                pre[i+1][j][k] = mp(j, k);
            }
            if(j<m && dp[i+1][j+1][k+a[i]-b[i]]<dp[i][j][k]+a[i]+b[i]) {
                dp[i+1][j+1][k+a[i]-b[i]] = dp[i][j][k]+a[i]+b[i];
                pre[i+1][j+1][k+a[i]-b[i]] = mp(j, k);
            }
        }
        int ix = -1;
        for(int i=0; i<=B; i++) if(dp[n][m][B+i]>=0 || dp[n][m][B-i]>=0) {
            ix = dp[n][m][B+i] > dp[n][m][B-i] ? B+i : B-i;
            break;
        }
        vector<int> ans;
        int x = m, y = ix;
        for(int i=n; i>0; i--) {
            const int nx = pre[i][x][y].first;
            const int ny = pre[i][x][y].second;
            if(nx<x) ans.push_back(i-1);
            x = nx, y = ny;
        }
        reverse(ans.begin(), ans.end());
        int av = 0, bv = 0;
        rep(i, ans.size()) av+=a[ans[i]], bv+=b[ans[i]];
        printf("Jury #%d\n", _q+1);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", av, bv);
        rep(i, ans.size()) printf(" %d", ans[i]+1);
        printf("\n\n");
    }
}
