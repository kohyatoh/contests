#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pt[1200], m, v[1200];
unsigned dp[16][1200];

int main() {
    for(int i=2; i<1200; i++) if(pt[i]==0) {
        v[m++] = i;
        for(int j=i*i; j<1200; j+=i) pt[j] = i;
    }
    dp[0][0] = 1;
    rep(k, m) for(int i=13; i>=0; i--) rep(j, 1200-v[k]) {
        dp[i+1][j+v[k]] += dp[i][j];
    }
    for(;;) {
        int n, k;
        scanf("%d%d", &n, &k);
        if(n==0 && k==0) return 0;
        printf("%u\n", dp[k][n]);
    }
}
