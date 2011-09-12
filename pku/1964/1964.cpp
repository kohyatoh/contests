#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, m;
char f[1100][1100];
int a[1100], b[1100];

int main() {
    scanf("%d", &T);
    rep(q, T) {
        scanf("%d%d", &n, &m);
        rep(i, 1100) rep(j, 1100) f[i][j]='R';
        rep(i, n) rep(j, m) scanf(" %c", f[i+1]+j+1);
        rep(i, m+2) a[i]=b[i]=0;
        a[0]=n+2;
        int maxs=0;
        for(int x=1; x<n+1; x++) {
            int s, xs, ys=0, yt=0;
            for(int y=1; y<m+2; y++) {
                if(f[x][y]=='R') {
                    a[y]=x;
                    b[y]=0;
                    yt=y;
                }
                else if(b[y]<yt) b[y]=yt;
                if(f[x+1][y-1]=='R') ys=y-1;
                if(a[ys]<a[y]) {
                    while(a[ys]<a[y]) {
                        xs=a[ys]; ys=b[ys]; 
                        s = (x-xs)*(y-ys-1);
                        if(maxs<s) maxs=s;
                    }
                    ys=y;
                }
            }
        }
        printf("%d\n", maxs*3);
    }
    return 0;
}

