#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, W, wall[32][32][4], ds[32][32];

int solve() {
    typedef pair<int, int> P;
    memset(ds, -1, sizeof(ds));
    queue<P> q;
    q.push(P(0, 0));
    ds[0][0] = 1;
    while(!q.empty()) {
        pair<int, int> vv(q.front());
        q.pop();
        const int x = vv.first;
        const int y = vv.second;
        if(x==H-1 && y==W-1) return ds[x][y];
        rep(d, 4) if(wall[x][y][d]==0) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(ds[nx][ny]==-1) {
                ds[nx][ny] = ds[x][y]+1;
                q.push(P(nx, ny));
            }
        }
    }
    return 0;
}

int main() {
    for(;;) {
        scanf("%d%d", &W, &H);
        if(W==0 && H==0) return 0;
        memset(wall, -1, sizeof(wall));
        rep(i, 2*H-1) {
            const int x = i/2;
            if(i%2==0) {
                rep(j, W-1) {
                    int a;
                    scanf("%d", &a);
                    wall[x][j][1] = wall[x][j+1][3] = a;
                }
            }
            else {
                rep(j, W) {
                    int a;
                    scanf("%d", &a);
                    wall[x][j][0] = wall[x+1][j][2] = a;
                }
            }
        }
        printf("%d\n", solve());
    }
}
