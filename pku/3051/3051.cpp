#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};

int w, h;
char f[100][1010];

int kount(int x, int y) {
    if(f[x][y]=='.') return 0;
    f[x][y]='.';
    int s=1;
    rep(d, 4) s+=kount(x+dx[d], y+dy[d]);
    return s;
}

int main() {
    scanf("%d%d", &w, &h);
    rep(i, w+2) rep(j, h+2) f[i][j]='.';
    rep(i, h) rep(j, w) scanf(" %c", f[j+1]+i+1);
    int ans=0;
    rep(i, w) rep(j, h) ans=std::max(ans, kount(i, j));
    printf("%d\n", ans);
    return 0;
}

