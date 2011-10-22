#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void cmax(int &a, int b) { if(a<b) a = b; }

int N, M, D[12000], dp[12000][512];

int main() {
    scanf("%d%d", &N, &M);
    rep(i, N) scanf("%d", D+i);
    rep(i, N) rep(j, M+1) {
        if(j<M) cmax(dp[i+1][j+1], dp[i][j]+D[i]);
        if(i+j<=N) cmax(dp[i+j][0], dp[i][j]);
        if(j==0) cmax(dp[i+1][0], dp[i][0]);
    }
    printf("%d\n", dp[N][0]);
    return 0;
}
