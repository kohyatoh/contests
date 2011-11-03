#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, h[128][128], dp[128][128][256];

struct node {
    int x, y, h;
    node(int x, int y, int h) : x(x), y(y), h(h) {}
};
bool operator<(const node& l, const node& r) {
    return l.x!=r.x ? l.x<r.x : l.y!=r.y ? l.y<r.y : l.h<r.h;
}

int dijkstra() {
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, node> > q;
    q.push(mp(0, node(0, 0, h[0][0])));
    while(!q.empty()) {
        pair<int, node> vv(q.top());
        q.pop();
        const int df = -vv.first;
        const int x = vv.second.x, y = vv.second.y, lh = vv.second.h;
        if(dp[x][y][lh]!=-1) continue;
        dp[x][y][lh] = df;
        if(x==n-1 && y==n-1) return df;
        rep(d, 4) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            const int nh = min(lh, h[nx][ny]);
            if(dp[nx][ny][nh]!=-1) continue;
            q.push(mp(-(max(lh+df, h[nx][ny])-nh), node(nx, ny, nh)));
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        scanf("%d", &n);
        rep(i, n) rep(j, n) scanf("%d", h[i]+j);
        printf("Scenario #%d:\n", _q+1);
        printf("%d\n", dijkstra());
        printf("\n");
    }
    return 0;
}
