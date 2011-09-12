#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int w, h, ans;
char f[32][32];

void dfs(int x, int y) {
    if(f[x][y]=='#') return ;
    f[x][y] = '#';
    ans++;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int main() {
    for(;;) {
        scanf("%d%d", &w, &h);
        if(w==0 && h==0) return 0;
        memset(f, '#', sizeof(f));
        rep(j, h) rep(i, w) scanf(" %c", f[i+1]+j+1);
        ans = 0;
        rep(i, w) rep(j, h) if(f[i+1][j+1]=='@') dfs(i+1, j+1);
        printf("%d\n", ans);
    }
}

