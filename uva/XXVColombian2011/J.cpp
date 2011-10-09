#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int N, t[200], b[200];
int dp[200][200];

int solve() {
    rep(i, 200) rep(j, 200) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, N) rep(j, N+1) {
        cmin(dp[i+1][min(j+b[i], N)], dp[i][j]+t[i]);
        if(j>0) cmin(dp[i+1][min(j+b[i]-1, N)], dp[i][j]+t[i]/2);
    }
    int ans = INF;
    rep(i, N+1) cmin(ans, dp[N][i]);
    return ans;
}

int main() {
    for(;;) {
        scanf("%d", &N);
        if(N==0) return 0;
        rep(i, N) scanf("%d%d", t+i, b+i);
        printf("%d\n", solve());
    }
}

