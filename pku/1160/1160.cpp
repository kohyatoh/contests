#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int n, m, xs[512], sum[512], a[512][512], dp[40][512];

int main() {
    scanf("%d%d", &m, &n);
    rep(i, m) scanf("%d", xs+i);
    sort(xs, xs+m);
    rep(i, m) sum[i+1] = sum[i] + xs[i];
    rep(i, m) {
        int z = i;
        for(int j=i+1; j<m; j++) {
            while(xs[z]-xs[i]<xs[j]-xs[z]) z++;
            a[i][j] = 0;
            a[i][j] += (sum[z]-sum[i])-xs[i]*(z-i);
            a[i][j] += xs[j]*(j-z)-(sum[j]-sum[z]);
        }
    }
    rep(i, 40) rep(j, 512) dp[i][j] = INF;
    rep(i, m) {
        dp[0][i] = 0;
        rep(j, i) dp[0][i] += xs[i]-xs[j];
    }
    rep(i, n-1) rep(j, m) {
        for(int k=j+1; k<m; k++) {
            cmin(dp[i+1][k], dp[i][j]+a[j][k]);
        }
    }
    int ans = INF;
    rep(i, m) {
        int z = dp[n-1][i];
        for(int j=i+1; j<m; j++) z += xs[j]-xs[i];
        cmin(ans, z);
    }
    printf("%d\n", ans);
    return 0;
}
