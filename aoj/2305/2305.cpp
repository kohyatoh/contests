#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define M (201000)
int N, a[40];
double dp[40][M];

inline double calc(double a, double b) { return fabs(a-b)/a; }

int main() {
    scanf("%d", &N);
    rep(i, N) scanf("%d", a+i);
    rep(i, N) rep(j, M) dp[i][j] = 1e100;
    rep(i, M) dp[0][i] = calc(a[0], i);
    rep(i, N-1) for(int j=1; j<M; j++) for(int k=j; k<M; k+=j) {
        dp[i+1][k] = min(dp[i+1][k], max(dp[i][j], calc(a[i+1], k)));
    }
    double ans = 1e100;
    rep(i, M) ans = min(ans, dp[N-1][i]);
    printf("%.12f\n", ans);
    return 0;
}

