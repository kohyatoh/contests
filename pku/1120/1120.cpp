#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, d[15], f[22][22], g[22][22];
int dx[5]={0, 1, 0, -1, 0};
int dy[5]={0, 0, 1, 0, -1};
char of[5]=".!X#";

int main() {
    scanf("%d", &n);
    rep(i, 16) scanf("%d", d+i);
    rep(i, 20) rep(j, 20) scanf("%d", f[i+1]+j+1);
    rep(q, n) {
        rep(i, 20) rep(j, 20) {
            int k=0;
            rep(z, 5) k+=f[i+1+dx[z]][j+1+dy[z]];
            g[i+1][j+1] = f[i+1][j+1]+d[k];
            if(g[i+1][j+1]<0) g[i+1][j+1]=0;
            if(g[i+1][j+1]>3) g[i+1][j+1]=3;
        }
        rep(i, 22) rep(j, 22) f[i][j]=g[i][j];
    }
    rep(i, 20) {
        rep(j, 20) putchar(of[f[i+1][j+1]]);
        putchar('\n');
    }
    return 0;
}

