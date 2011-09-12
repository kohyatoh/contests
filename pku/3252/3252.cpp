#include <stdio.h>
#define rep(i, n) for(int i=0; i<n; i++)

int dp[100][100];

int calc(unsigned a) {
    int k=0, c=0, o=0;
    while((1u<<k)<=a) k++;
    for(int i=2; i<k; i++) rep(j, i/2) c+=dp[i-1][j];
    for(int i=k-2; i>=0; i--) if(a&(1u<<i)) {
        rep(j, k/2-o) c+=dp[i][j];
        o++;
    }
    return c;
}

int main() {
    dp[0][0]=1;
    rep(i, 99) rep(j, i+1) dp[i+1][j]+=dp[i][j], dp[i+1][j+1]+=dp[i][j];
    int s, f;
    scanf("%d%d", &s, &f);
    printf("%d\n", calc(f+1)-calc(s));
    return 0;
}
