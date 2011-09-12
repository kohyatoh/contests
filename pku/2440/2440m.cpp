#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define MOD (2005)

int n, a[31][4][4]={{{1,0,1,0},{1,0,0,0},{0,1,0,1},{0,1,0,0}}};

int main() {
    rep(x, 30) rep(i, 4) rep(j, 4) rep(k, 4) {
        a[x+1][i][j] = (a[x+1][i][j]+a[x][i][k]*a[x][k][j])%MOD;
    }
    while(scanf("%d", &n)!=EOF) {
        int r[4]={1, 0, 0, 0}, t[4];
        rep(x, 30) if(n&(1<<x)) {
            rep(i, 4) t[i] = 0;
            rep(i, 4) rep(j, 4) t[i]=(t[i]+a[x][i][j]*r[j])%MOD;
            rep(i, 4) r[i] = t[i];
        }
        int ans = 0;
        rep(i, 4) ans=(ans+r[i])%MOD;
        printf("%d\n", ans);
    }
    return 0;
}


