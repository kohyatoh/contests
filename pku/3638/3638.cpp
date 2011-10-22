#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1e100)
inline void cmin(double &a, double b) { if(a>b) a = b; }

int N, M, x[256];
double c[256][256], dp[256][256];

double solve() {
    memset(c, 0, sizeof(c));;
    rep(i, N) for(int j=i+1; j<N; j++) {
        double a = 1.0/(j-i);
        for(int k=i+1; k<j; k++) c[i][j] += fabs(x[i]+(x[j]-x[i])*(k-i)*a-x[k]);
    }
    rep(i, N) rep(j, M) dp[i][j] = INF;
    rep(i, M) dp[0][i] = 0;
    for(int k=1; k<N; k++) for(int i=max(1, M-N+k); i<M; i++) {
        rep(x, k) cmin(dp[k][i], dp[x][i-1]+c[x][k]);
    }
    return dp[N-1][M-1]/N;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        rep(i, N) scanf("%d", x+i);
        printf("%.4f\n", solve());
    }
    return 0;
}
