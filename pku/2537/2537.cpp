#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

int n, k;
double dp[100][10];

int main() {
    while(scanf("%d%d", &k, &n)!=EOF) {
        memset(dp, 0, sizeof(dp));
        rep(i, k+1) dp[0][i]=1;
        for(int i=1; i<n; i++) rep(j, k+1) {
            for(int d=-1; d<=1; d++) if(0<=j+d && j+d<=k) {
                dp[i][j] += dp[i-1][j+d]/(k+1);
            }
        }
        double ans=0;
        rep(i, k+1) ans+=dp[n-1][i]/(k+1);
        printf("%.5f\n", ans*100);
    }
}

