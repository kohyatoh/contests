#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define INF (1<<20)

struct ST {
    int x, y, k;
    ST() {}
    ST(int x, int y, int k) : x(x), y(y), k(k) {}
};
bool operator<(const ST& l, const ST& r) {
    if (l.x != r.x) return l.x < r.x;
    if (l.y != r.y) return l.y < r.y;
    return l.k < r.k;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, K, a[128][128], of[128][128];
int vis[128][128][1<<5];
char f[128][128];

int solve() {
    int gx = -1, gy = -1;
    rep (i, n) rep (j, m) if (f[i][j] == 'G') gx = i+1, gy = j+1;
    priority_queue<pair<int, ST> > q;
    rep (i, n) rep (j, m) if (f[i][j] == 'S') q.push(mp(0, ST(i+1, j+1, 0)));
    while (!q.empty()) {
        const pair<int, ST> vv = q.top();
        const ST cur = vv.second;
        q.pop();
        if (vis[cur.x][cur.y][cur.k]) continue;
        vis[cur.x][cur.y][cur.k] = 1;
        if (gx == cur.x && gy == cur.y && (1<<K)-1 == cur.k) return -vv.first;
        rep (d, 4) {
            const int x = cur.x+dx[d], y = cur.y+dy[d];
            if (a[x][y] == INF) continue;
            q.push(mp(vv.first-a[cur.x][cur.y], ST(x, y, cur.k|of[x][y])));
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &m, &n);
    rep (i, n) rep (j, m) scanf(" %c", f[i]+j);
    rep (i, 128) rep (j, 128) a[i][j] = INF;
    rep (i, n) rep (j, m) if (f[i][j] != '#') a[i+1][j+1] = 1;
    rep (i, n) rep (j, m) if (f[i][j] == '#') {
        for (int x = i-2; x <= i+2; x++) {
            for (int y = j-2; y <= j+2; y++) {
                a[x+1][y+1] = max(a[x+1][y+1], 4-max(abs(x-i), abs(y-j)));
            }
        }
    }
    rep (i, n) rep (j, m) if (f[i][j] == 'M') {
        of[i+1][j+1] = 1<<K;
        K++;
    }
    printf("%d\n", solve());
    return 0;
}
