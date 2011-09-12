#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, m, h[1100], dp[1100][2000];
int INF = 1<<20;

void rec_pr(int i, int ch) {
    if(i<0) return ;
    if(dp[i+1][ch]==dp[i][ch+h[i]]) { rec_pr(i-1, ch+h[i]); putchar('D'); }
    else { rec_pr(i-1, ch-h[i]); putchar('U'); }
    if(i==m-1) putchar('\n');
}

int main() {
    scanf("%d", &T);
    rep(q, T) {
        scanf("%d", &m);
        rep(i, m) scanf("%d", h+i);
        rep(i, 1100) rep(j, 2000) dp[i][j]=INF;
        dp[0][0]=0;
        rep(i, m) {
            rep(j, 2000) if(dp[i][j]!=INF) {
                if(j-h[i]>=0) dp[i+1][j-h[i]] = min(dp[i+1][j-h[i]], dp[i][j]);
                dp[i+1][j+h[i]] = min(dp[i+1][j+h[i]], max(j+h[i], dp[i][j]));
            }
        }
        if(dp[m][0]==INF) printf("IMPOSSIBLE\n");
        else rec_pr(m-1, 0);
    }
    return 0;
}

