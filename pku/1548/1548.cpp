#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int f[50][50];

int main() {
    for(;;) {
        rep(i, 50) rep(j, 50) f[i][j]=0;
        for(;;) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(x==0 && y==0) break;
            if(x==-1 && y==-1) return 0;
            f[x][y]=1;
        }
        int cur=0, ans=0;
        rep(i, 50) {
            cur=-1;
            rep(j, 50) if(f[i][j]==1) f[i][j]=0, cur=j;
            if(cur>=0) {
                ans++;
                for(int k=i+1; k<50; k++) {
                    for(int j=cur; j<50; j++) if(f[k][j]) f[k][j]=0, cur=j;
                }
            }
        }
        printf("%d\n", ans);
    }
}

