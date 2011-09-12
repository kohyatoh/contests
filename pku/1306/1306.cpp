#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

unsigned d[110][110];

int main() {
    d[0][0]=1;
    rep(i, 100) rep(j, i+1) d[i+1][j]+=d[i][j], d[i+1][j+1]+=d[i][j];
    for(;;) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        printf("%d things taken %d at a time is %u exactly.\n", n, m, d[n][m]);
    }
}
