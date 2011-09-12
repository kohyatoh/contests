#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, p, dp[50000];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, 50000) dp[i]=INT_MAX;
        rep(i, n) {
            scanf("%d", &p);
            *std::lower_bound(dp, dp+50000, p)=p;
        }
        int c=0;
        rep(i, n) if(dp[i]<INT_MAX) c=i+1;
        printf("%d\n", c);
    }
    return 0;
}
