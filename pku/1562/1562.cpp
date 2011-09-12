#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int m, n;
char f[200][200];

void draw(int x, int y) {
    if(f[x][y]!='@') return ;
    f[x][y]='*';
    rep(dx, 3) rep(dy, 3) draw(x+dx-1, y+dy-1);
}

int main() {
    for(;;) {
        scanf("%d%d", &m, &n);
        if(m==0) return 0;
        rep(i, m+2) rep(j, n+2) f[i][j]='*';
        rep(i, m) rep(j, n) scanf(" %c", f[i+1]+j+1);
        int ans=0;
        rep(i, m+2) rep(j, n+2) if(f[i][j]=='@') draw(i, j), ans++;
        printf("%d\n", ans);
    }
}

