#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void cmax(int &a, int b) { if(a<b) a=b; }
#define INF (1<<28)

int L, N, M, X, se[200], ss[200], e[200], s[200], dp[200][1024];
char buf[128];

int main() {
    for(;;) {
        scanf("%d%d%d%d", &L, &N, &M, &X);
        if(L==0) return 0;
        rep(i, N) scanf("%s%d%d", buf, se+i, ss+i);
        rep(i, M) scanf("%s%d%d", buf, e+i, s+i);
        rep(i, 200) rep(j, 1024) dp[i][j] = -INF;
        dp[0][0] = 0;
        rep(k, M) for(int i=k; i>=0; i--) rep(j, L+1-e[k]) {
            cmax(dp[i+1][j+e[k]], dp[i][j]+s[k]);
        }
        for(int x=X+1; x<=M; x++) rep(i, L+1) cmax(dp[X][i], dp[x][i]);
        rep(i, L) cmax(dp[X][i+1], dp[X][i]);
        int ans = -INF;
        rep(i, N) if(se[i]<=L) {
            cmax(ans, ss[i]+dp[X][L-se[i]]);
            rep(j, i) if(se[i]+se[j]<=L) {
                cmax(ans, ss[i]+ss[j]+dp[X][L-se[i]-se[j]]);
            }
        }
        printf("%d\n", ans);
    }
}
