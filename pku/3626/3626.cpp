#include <stdio.h>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define B (512)
int f[1024][1024];

int bfs(int sx, int sy, int tx, int ty) {
    queue<pair<int, int> > q;
    q.push(mp(sx, sy));
    f[sx][sy] = 1;
    while(!q.empty()) {
        pair<int, int> vv(q.front());
        q.pop();
        const int x = vv.first;
        const int y = vv.second;
        if(x==tx && y==ty) return f[x][y]-1;
        rep(d, 4) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(f[nx][ny]==0) {
                q.push(mp(nx, ny));
                f[nx][ny] = f[x][y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int X, Y, N;
    scanf("%d%d%d", &X, &Y, &N);
    int minx = min(B-1, X+B-1), maxx = max(B+1, X+B+1);
    int miny = min(B-1, Y+B-1), maxy = max(B+1, Y+B+1);
    rep(i, N) {
        int a, b;
        scanf("%d%d", &a, &b);
        f[a+B][b+B] = -1;
        minx = min(minx, a+B-2);
        maxx = max(maxx, a+B+2);
        miny = min(miny, b+B-2);
        maxy = max(maxy, a+B+2);
    }
    rep(i, 1024) f[minx][i] = -1;
    rep(i, 1024) f[maxx][i] = -1;
    rep(i, 1024) f[i][miny] = -1;
    rep(i, 1024) f[i][maxy] = -1;
    printf("%d\n", bfs(B, B, X+B, Y+B));
    return 0;
}
