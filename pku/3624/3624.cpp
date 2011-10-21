#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
void cmax(int &a, int b) { if(a<b) a = b; }

int N, M, w[4000], d[4000], dp[13000];

int main() {
    scanf("%d%d", &N, &M);
    rep(i, N) scanf("%d%d", w+i, d+i);
    rep(k, N) for(int i=M-w[k]; i>=0; i--) cmax(dp[i+w[k]], dp[i]+d[k]);
    printf("%d\n", dp[M]);
    return 0;
}
