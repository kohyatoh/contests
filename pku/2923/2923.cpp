#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int Q, n, c[2], w[10], cann[2], cans[2][1024], dp[2][1024];

int main() {
    scanf("%d", &Q);
    rep(q, Q) {
        scanf("%d%d%d", &n, c, c+1);
        rep(i, n) scanf("%d", w+i);
        int nn=1<<n;
        rep(i, 2) cann[i]=0;
        rep(b, nn) {
            int s=0;
            rep(i, n) if(b&(1<<i)) s+=w[i];
            rep(i, 2) if(c[i]>=s) cans[i][cann[i]++]=b;
        }
        rep(i, 2) {
            rep(j, 1024) dp[i][j]=n+1;
            dp[i][0]=0;
            rep(b, nn) rep(k, cann[i]) {
                dp[i][b|cans[i][k]]=min(dp[i][b|cans[i][k]], dp[i][b]+1);
            }
        }
        int ans=n+1;
        rep(b, nn) ans=min(ans, max(dp[0][b], dp[1][(nn-1)&~b]));
        printf("Scenario #%d:\n%d\n\n", q+1, ans);
    }
    return 0;
}

