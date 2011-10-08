#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct node {
    int w, x, y;
    node(int w, int x, int y) : w(w), x(x), y(y) {}
};
inline bool operator<(const node& l, const node& r) {
    return l.w!=r.w ? l.w<r.w : l.x!=r.x ? l.x<r.x : l.y<r.y;
}

int H, W;
int m, wall[32][32][4], bcost[2000][32][32], dp[2000][32][32];

void dfs(int sx, int sy, int br) {
    memset(bcost[br], -1, sizeof(bcost[br]));
    queue<node> q;
    q.push(node(0, sx, sy));
    bcost[br][sx][sy] = 0;
    while(!q.empty()) {
        const node v(q.front());
        q.pop();
        rep(d, 4) if(wall[v.x][v.y][d]>=0 && wall[v.x][v.y][d]!=br) {
            const int nx = v.x+dx[d], ny = v.y+dy[d];
            if(bcost[br][nx][ny]!=-1) continue;
            q.push(node(v.w+1, nx, ny));
            bcost[br][nx][ny] = v.w+1;
        }
    }
}

int solve() {
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, node> > q;
    q.push(mp(0, node(0, 0, 0)));
    while(!q.empty()) {
        const pair<int, node> vv(q.top());
        q.pop();
        const int c = -vv.first;
        const int w = vv.second.w, x = vv.second.x, y = vv.second.y;
        if(dp[w][x][y]!=-1) continue;
        dp[w][x][y] = c;
        if(x==H-1 && y==W-1) return c;
        rep(d, 4) if(wall[x][y][d]>=0) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(dp[w+1][nx][ny]!=-1) continue;
            const int wk = wall[x][y][d];
            if(bcost[wk][x][y]!=-1) {
                const int nc = max(c, w+bcost[wk][x][y]);
                q.push(mp(-nc, node(w+1, nx, ny)));
            }
        }
    }
    return -1;
}

int main() {
    for(;;) {
        scanf("%d%d", &H, &W);
        if(H==0 && W==0) return 0;
        memset(wall, -1, sizeof(wall));
        m = 0;
        rep(i, 2*H-1) {
            int ex;
            if(i%2==0) rep(j, W-1) {
                scanf("%d", &ex);
                wall[i/2][j][1] = wall[i/2][j+1][3] = ex ? -1 : m;
                if(ex==0) m++;
            }
            else rep(j, W) {
                scanf("%d", &ex);
                wall[i/2][j][0] = wall[i/2+1][j][2] = ex ? -1 : m;
                if(ex==0) m++;
            }
        }
        rep(i, m) dfs(H-1, W-1, i);
        printf("%d\n", solve());
    }
}
