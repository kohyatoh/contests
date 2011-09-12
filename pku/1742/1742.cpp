#include <stdio.h>
#include <numeric>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[200], c[200];
int dp[100010], dc[100010];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) scanf("%d", a+i);
        rep(i, n) scanf("%d", c+i);
        rep(i, m+1) dp[i]=0;
        dp[0]=1;
        rep(i, n) {
            rep(k, m+1) dc[k]=0;
            rep(k, m-a[i]+1) if(dp[k] && dc[k]<c[i]) {
                if(dp[k+a[i]]) dc[k+a[i]]=min(dc[k+a[i]], dc[k]+1);
                else {
                    dp[k+a[i]] = 1;
                    dc[k+a[i]] = dc[k]+1;
                }
            }
        }
        printf("%d\n", accumulate(dp+1, dp+m+1, 0));
    }
}
