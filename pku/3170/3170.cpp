#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct node {int x, y, z; node(int x, int y, int z) : x(x), y(y), z(z) {} };
bool operator<(const node& l, const node& r) {
    return l.x!=r.x ? l.x<r.x : l.y!=r.y ? l.y<r.y : l.z<r.z;
}

int w, h, f[1024][1024], vis[1024][1024][2];

int main() {
    rep(i, 1024) rep(j, 1024) f[i][j] = 1;
    scanf("%d%d", &w, &h);
    rep(j, h) rep(i, w) scanf("%d", &f[i+1][j+1]);
    w += 2, h += 2;
    queue<pair<int, node> > q;
    rep(i, w) rep(j, h) if(f[i][j]==2) {
        q.push(mp(0, node(i, j, 0)));
        f[i][j] = 0;
    }
    while(!q.empty()) {
        pair<int, node> v(q.front());
        q.pop();
        node t = v.second;
        if(vis[t.x][t.y][t.z]) continue;
        vis[t.x][t.y][t.z] = 1;
        rep(d, 4) {
            const int nx=t.x+dx[d], ny=t.y+dy[d];
            if(f[nx][ny]==0) q.push(mp(v.first+1, node(nx, ny, t.z)));
            if(f[nx][ny]==1) continue;
            if(f[nx][ny]==3 && t.z==1) {
                printf("%d\n", v.first+1);
                return 0;
            }
            if(f[nx][ny]==4) {
                q.push(mp(v.first+1, node(nx, ny, min(t.z+1, 1))));
            }
        }
    }
}
