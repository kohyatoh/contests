#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void cmax(int &a, int b) { if(a<b) a = b; }

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, f[32][32];

int dfs(int x, int y, int b) {
    b |= f[x][y];
    int ans = 1;
    rep(d, 4) {
        const int nx = x+dx[d], ny = y+dy[d];
        if(f[nx][ny]!=-1 && (b&f[nx][ny])==0) cmax(ans, dfs(nx, ny, b)+1);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(f, -1, sizeof(f));
    rep(i, n) rep(j, m) {
        char ch;
        scanf(" %c", &ch);
        f[i+1][j+1] = 1<<(ch-'A');
    }
    printf("%d\n", dfs(1, 1, 0));
    return 0;
}
