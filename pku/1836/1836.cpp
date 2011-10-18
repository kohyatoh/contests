#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
double a[1024], dp[1024];
int x[2][1024];

void lis(int *out) {
    rep(i, n+1) dp[i] = 1e100;
    int m = 0;
    rep(i, n) {
        out[i] = m;
        const int ix = lower_bound(dp, dp+m, a[i])-dp;
        if(ix==m) m++;
        dp[ix] = a[i];
    }
    out[n] = m;
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%lf", a+i);
    rep(i, 2) {
        lis(x[i]);
        reverse(a, a+n);
    }
    int ans = 0;
    rep(i, n+1) ans = max(ans, x[0][i]+x[1][n-i]);
    printf("%d\n", n-ans);
    return 0;
}
