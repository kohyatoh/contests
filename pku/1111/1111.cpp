#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m;
char f[32][32];

int rec(int x, int y) {
    if(f[x][y]!='X') return 0;
    f[x][y] = 'Y';
    int ans = 0;
    rep(d, 8) {
        const int nx = x+dx[d], ny = y+dy[d];
        if(d%2==0 && f[nx][ny]=='.') ans++;
        ans += rec(nx, ny);
    }
    return ans;
}

int main() {
    for(;;) {
        int sx, sy;
        scanf("%d%d%d%d", &n, &m, &sx, &sy);
        if(n==0 && m==0) return 0;
        memset(f, '.', sizeof(f));
        rep(i, n) rep(j, m) scanf(" %c", f[i+1]+j+1);
        printf("%d\n", rec(sx, sy));
    }
}
