#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, k, a[100], dp[4][200];

int main() {
    rep(i, 20) rep(j, 3) a[k++]=(i+1)*(j+1);
    a[k++] = 25;
    a[k++] = 50;
    rep(i, 4) dp[i][0] = 1;
    rep(r, k) {
        for(int x=2; x>=0; x--) {
            for(int i=199; i>=0; i--) if(dp[x][i]) {
                rep(j, 3-x) dp[x+j+1][i+a[r]*(j+1)]+=dp[x][i];
            }
        }
    }
    scanf("%d", &T);
    rep(i, T) {
        scanf("%d", &n);
        printf("Scenario #%d:\n%d\n\n", i+1, dp[3][n]);
    }
}

