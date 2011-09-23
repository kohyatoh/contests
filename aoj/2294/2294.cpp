#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int H, N, P, M, K, of[600];
double dp[600][128][128];

int main() {
    scanf("%d%d%d%d%d", &H, &N, &P, &M, &K);
    P--;
    memset(of, -1, sizeof(of));
    rep(i, M) {
        int A, B;
        scanf("%d%d", &A, &B);
        of[H-A] = B-1;
    }
    dp[0][0][P] = 1;
    int fix = 0;
    rep(k, H) {
        if(of[k]!=-1) fix++;
        rep(i, K+1) rep(j, N) {
            if(of[k]!=-1) {
                if(j==of[k]) dp[k+1][i][j+1] += dp[k][i][j];
                else if(j-1==of[k]) dp[k+1][i][j-1] += dp[k][i][j];
                else dp[k+1][i][j] += dp[k][i][j];
            }
            else {
                const double p = (double)(K-i)/(H-k-M+fix);
                dp[k+1][i][j] += dp[k][i][j]*(1-p);
                if(N==1) dp[k+1][i+1][j] += dp[k][i][j]*p;
                else {
                    int c = N-1;
                    if(j<N-1) {
                        dp[k+1][i+1][j+1] += dp[k][i][j]*p/(N-1);
                        c--;
                    }
                    if(j>0) {
                        dp[k+1][i+1][j-1] += dp[k][i][j]*p/(N-1);
                        c--;
                    }
                    dp[k+1][i+1][j] += dp[k][i][j]*p*c/(N-1);
                }
            }
        }
    }
    double ans = 0;
    rep(i, N) if(ans<dp[H][K][i]) ans=dp[H][K][i];
    printf("%.9f\n", ans);
    return 0;
}
