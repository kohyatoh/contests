#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dxq[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyq[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dxk[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dyk[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int f[1050][1050];
int n, m, k[3], x[3][100], y[3][100];

int main() {
    for(int q=0;; q++) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, 1050) rep(j, 1050) f[i][j]=0;
        rep(i, n) rep(j, m) f[i+10][j+10]=1;
        rep(i, 3) {
            scanf("%d", k+i);
            rep(j, k[i]) scanf("%d%d", x[i]+j, y[i]+j);
            rep(j, k[i]) x[i][j]+=9, y[i][j]+=9;
            rep(j, k[i]) f[x[i][j]][y[i][j]]=0;
        }
        rep(i, k[0]) rep(d, 8) {
            int cx=x[0][i]+dxq[d], cy=y[0][i]+dyq[d];
            while(f[cx][cy]) { f[cx][cy]=-1; cx+=dxq[d], cy+=dyq[d]; }
        }
        rep(i, k[1]) rep(d, 8) f[x[1][i]+dxk[d]][y[1][i]+dyk[d]]=-1;
        int ans=0;
        rep(i, 1050) rep(j, 1050) if(f[i][j]==1) ans++;
        printf("Board %d has %d safe squares.\n", q+1, ans);
    }
}

