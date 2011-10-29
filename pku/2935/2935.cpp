#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dof[] = "ESWN";

int sx, sy, gx, gy, wall[8][8][4], pre[8][8];

void bfs() {
    memset(pre, -1, sizeof(pre));
    queue<pair<int, int> > q;
    q.push(mp(sx, sy));
    pre[sx][sy] = 0;
    while(!q.empty()) {
        pair<int, int> vv(q.front());
        q.pop();
        const int x = vv.first, y = vv.second;
        rep(d, 4) if(wall[x][y][d]==0) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(pre[nx][ny]==-1) {
                pre[nx][ny] = d;
                q.push(mp(nx, ny));
            }
        }
    }
}

int main() {
    for(;;) {
        scanf("%d%d", &sx, &sy);
        if(sx==0 && sy==0) return 0;
        scanf("%d%d", &gx, &gy);
        memset(wall, 0, sizeof(wall));
        rep(i, 8) wall[1][i][2] = 1;
        rep(i, 8) wall[6][i][0] = 1;
        rep(i, 8) wall[i][1][3] = 1;
        rep(i, 8) wall[i][6][1] = 1;
        rep(_, 3) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(x1==x2) {
                if(y2<y1) swap(y1, y2);
                for(int y=y1+1; y<=y2; y++) {
                    wall[x1][y][0] = wall[x1+1][y][2] = 1;
                }
            }
            else {
                if(x2<x1) swap(x1, x2);
                for(int x=x1+1; x<=x2; x++) {
                    wall[x][y1][1] = wall[x][y1+1][3] = 1;
                }
            }
        }
        bfs();
        string r;
        int x = gx, y = gy;
        while(x!=sx || y!=sy) {
            const int d = pre[x][y];
            r += dof[d];
            x += dx[(d+2)%4];
            y += dy[(d+2)%4];
        }
        reverse(r.begin(), r.end());
        printf("%s\n", r.c_str());
    }
}
