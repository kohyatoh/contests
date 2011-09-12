#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, v[4][4], dp[2][3][3][7][7][7][7];

int dx[9] = {0, 0, 1, 0, -1, 0, 2, 0, -2};
int dy[9] = {0, 1, 0, -1, 0, 2, 0, -2, 0};

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        int (*cur)[3][7][7][7][7]=dp[0], (*nxt)[3][7][7][7][7]=dp[1];
        memset(cur, 0, sizeof(*dp));
        cur[1][1][1][1][1][1] = 1;
        rep(i, n) {
            memset(v, 0, sizeof(v));
            int f;
            rep(x, 4) rep(y, 4) {
                scanf("%d", &f);
                if(f) {
                    v[x][y]=1;
                    if(x>0) v[x-1][y]=1;
                    if(y>0) v[x][y-1]=1;
                    if(x>0 && y>0) v[x-1][y-1]=1;
                }
            }
            if(i==n-1) break;
            memset(nxt, 0, sizeof(*dp));
            rep(x, 3) rep(y, 3) if(v[x][y]==0) {
                rep(a, 7) rep(b, 7) rep(c, 7) rep(d, 7) {
                    if(cur[x][y][a][b][c][d]) {
                        rep(dir, 9) {
                            int nx=x+dx[dir], ny=y+dy[dir];
                            if(nx<0 || nx>2 || ny<0 || ny>2) continue;
                            int na=a+1, nb=b+1, nc=c+1, nd=d+1;
                            if(nx==0 && ny==0) na=0;
                            if(nx==2 && ny==0) nb=0;
                            if(nx==0 && ny==2) nc=0;
                            if(nx==2 && ny==2) nd=0;
                            if(na<7 && nb<7 && nc<7 && nd<7) {
                                nxt[nx][ny][na][nb][nc][nd] = 1;
                            }
                        }
                    }
                }
            }
            std::swap(cur, nxt);
        }
        int ans=0;
        rep(x, 3) rep(y, 3) if(v[x][y]==0) {
            rep(a, 7) rep(b, 7) rep(c, 7) rep(d, 7) {
                if(cur[x][y][a][b][c][d]) ans=1;
            }
        }
        printf("%d\n", ans);
    }
}
