#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
int n, m, w[64][64], vis[64][64]; 

int visit(int x, int y) {
    if(vis[x][y]!=0) return 0;
    vis[x][y] = 1;
    int c = 1;
    rep(d, 4) if((w[x][y]&(1<<d))==0) c += visit(x+dx[d], y+dy[d]);
    return c;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) scanf("%d", w[i]+j);
    int k = 0, c = 0;
    rep(i, n) rep(j, m) if(vis[i][j]==0) {
        c = max(c, visit(i, j));
        k++;
    }
    printf("%d\n", k);
    printf("%d\n", c);
    return 0;
}
