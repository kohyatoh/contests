#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dp[1000][200], ans[200];

int main() {
    rep(i, 1000) for(int j=2; j<200; j++) dp[i][j]=(dp[i][j-1]+i)%j;
    for(int i=3; i<150; i++) for(int j=1; ; j++) {
        if((i-(j-1)%i+dp[j][i])%i==1) {
            ans[i]=j;
            break;
        }
    }
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        printf("%d\n", ans[n]);
    }
    return 0;
}

