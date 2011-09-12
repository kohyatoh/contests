#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, x[2000], y[2000];
double d[2000][2000], dp[2000][2000];

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        rep(i, n) scanf("%d%d", x+i, y+i);
        rep(i, n) rep(j, n) d[i][j]=hypot(x[j]-x[i], y[j]-y[i]);
        rep(i, n) rep(j, n) dp[i][j]=1e100;
        dp[0][0] = 0;
        rep(i, n-1) rep(j, i+1) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+d[i][i+1]);
            dp[i+1][i] = min(dp[i+1][i], dp[i][j]+d[j][i+1]);
            dp[i+1][i+1] = min(dp[i+1][i+1], dp[i][j]+d[i][i+1]+d[j][i+1]);
        }
        printf("%.2f\n", dp[n-1][n-1]);
    }
    return 0;
}

