#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<28)
const int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
int g[64][64];
char a[8], b[8];

int main() {
    rep(i, 64) rep(j, 64) g[i][j]=(i!=j)*INF;
    rep(x, 8) rep(y, 8) rep(d, 8) {
        int nx=x+dx[d], ny=y+dy[d];
        if(0<=nx && nx<8 && 0<=ny && ny<8) {
            g[x*8+y][nx*8+ny]=g[nx*8+ny][x*8+y]=1;
        }
    }
    rep(k, 64) rep(i, 64) rep(j, 64) g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
    while(scanf(" %s%s", a, b)!=EOF) {
        int sx=a[0]-'a', sy=a[1]-'1', tx=b[0]-'a', ty=b[1]-'1';
        printf("To get from %s to %s takes %d knight moves.\n", a, b, g[sx*8+sy][tx*8+ty]);
    }
    return 0;
}

