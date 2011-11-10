#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int w, h, wall[32][32][4], vis[32][32];

void visit(int i, int j) {
    if(vis[i][j]) return ;
    vis[i][j] = 1;
    rep(d, 4) if(wall[i][j][d]==0) {
        visit(i+dx[d], j+dy[d]);
    }
}

int main() {
    for(;;) {
        scanf(" %d%d", &h, &w);
        if(w==0 && h==0) return 0;
        w += 2, h += 2;
        memset(wall, 0, sizeof(wall));
        rep(i, h) wall[1][i][2] = wall[w-2][i][0] = 1;
        rep(i, w) wall[i][1][3] = wall[i][h-2][1] = 1;
        int m;
        scanf("%d", &m);
        while(m--) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1++, y1++, x2++, y2++;
            if(x1>x2) swap(x1, x2);
            if(y1>y2) swap(y1, y2);
            for(int x=x1; x<x2; x++) {
                wall[x][y1][3] = wall[x][y1-1][1] = 1;
                wall[x][y2][3] = wall[x][y2-1][1] = 1;
            }
            for(int y=y1; y<y2; y++) {
                wall[x1][y][2] = wall[x1-1][y][0] = 1;
                wall[x2][y][2] = wall[x2-1][y][0] = 1;
            }
        }
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i=1; i<w-1; i++) for(int j=1; j<h-1; j++) {
            if(vis[i][j]==0) {
                ans++;
                visit(i, j);
            }
        }
        printf("%d\n", ans);
    }
}
