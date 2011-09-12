#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int sq[256], dp[5][40000];

int main() {
    rep(i, 256) sq[i]=i*i;
    rep(k, 256) {
        dp[1][sq[k]]++;
        for(int x=1; x<4; x++) {
            rep(i, 40000-sq[k]) {
                dp[x+1][i+sq[k]] += dp[x][i];
            }
        }
    }
    for(;;) {
        int a;
        scanf("%d", &a);
        if(a==0) return 0;
        printf("%d\n", dp[4][a]);
    }
    return 0;
}

