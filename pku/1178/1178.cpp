#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int kp, n, ps[64], g[64][64];

int scanP() {
    char x, y;
    if(scanf(" %c%c", &x, &y)==EOF) return -1;
    return (x-'A')*8 + (y-'1');
}

int main() {
    rep(i, 64) rep(j, 64) g[i][j] = i==j ? 0 : INF;
    rep(i, 64) {
        const int x = i/8, y = i%8;
        rep(d, 8) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(nx<0 || nx>=8 || ny<0 || ny>=8) continue;
            g[i][nx*8+ny] = 1;
        }
    }
    rep(k, 64) rep(i, 64) rep(j, 64) cmin(g[i][j], g[i][k]+g[k][j]);
    kp = scanP();
    while((ps[n]=scanP())!=-1) n++;
    int ans = INF;
    rep(p, 64) {
        int s = 0;
        rep(i, n) s += g[p][ps[i]];
        cmin(ans, s+abs(kp/8-p/8)+abs(kp%8-p%8));
        rep(z, 64) rep(i, n) {
            const int km = abs(kp/8-z/8)+abs(kp%8-z%8);
            cmin(ans, s-g[p][ps[i]]+g[ps[i]][z]+g[p][z]+km);
        }
    }
    printf("%d\n", ans);
    return 0;
}
