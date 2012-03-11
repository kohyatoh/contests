#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double dp[32][32];

double solve(int M, int N, double X) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep (i, N) rep (j, N) {
        for (int k = 1; k <= N-j; k++) {
            dp[i+1][j+k] += dp[i][j] * cos(k*X/N);
        }
    }
    double ans = 0;
    rep (k, N+1) {
        double c = dp[k][N];
        rep (i, k) c = c * (M-i) / (i+1);
        ans += c;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int M, N;
        double X;
        scanf(" %d%d%lf", &M, &N, &X);
        printf("%.10f\n", solve(M, N, X));
    }
    return 0;
}
