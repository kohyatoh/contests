#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1000000)
int n, a[2000], dp[2000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    rep(i, n+2) dp[i]=INF;
    rep(i, n) *std::lower_bound(dp, dp+n+1, a[i])=a[i];
    int m=0;
    while(dp[m]!=INF) m++;
    printf("%d\n", m);
    return 0;
}
