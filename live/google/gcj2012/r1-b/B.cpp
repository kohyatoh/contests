#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, N, M, c[128][128], f[128][128];
int dp[128][128], has[128][128];

int can(int cx, int cy, int nx, int ny) {
    if (f[cx][cy] > c[nx][ny] - 50) return false;
    if (f[nx][ny] > c[nx][ny] - 50) return false;
    if (f[nx][ny] > c[cx][cy] - 50) return false;
    return true;
}

int waitt(int x, int y, int h) {
    if (h <= c[x][y] - 50) return 0;
    return h - (c[x][y]-50);
}

int solve() {
    priority_queue<pair<double, pair<int, int> > > q;
    // (1, 1) ~ (N, M)
    queue<pair<int, int> > sq;
    memset(has, 0, sizeof(has));
    sq.push(mp(1, 1));
    while (!sq.empty()) {
        pair<int, int> vv(sq.front());
        sq.pop();
        const int x = vv.first;
        const int y = vv.second;
        if (has[x][y]) continue;
        has[x][y] = 1;
        q.push(mp(0, mp(x, y)));
        rep (d, 4) {
            const int nx = x + dx[d];
            const int ny = y + dy[d];
            if (can(x, y, nx, ny) && has[nx][ny] == 0) {
                if (waitt(nx, ny, H) == 0) sq.push(mp(nx, ny));
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    while (!q.empty()) {
        pair<int, pair<int, int> > vv(q.top());
        q.pop();
        const int t = -vv.first;
        const int h = H - t;
        const int x = vv.second.first;
        const int y = vv.second.second;
        if (dp[x][y] >= 0) continue;
        dp[x][y] = t;
        if (x == N && y == M) return t;
        rep (d, 4) {
            const int nx = x + dx[d];
            const int ny = y + dy[d];
            if (can(x, y, nx, ny) && dp[nx][ny] == -1) {
                const int w = waitt(nx, ny, h);
                const int nh = H - t - w;
                const int st = nh >= f[x][y] + 20 ? 10 : 100;
                q.push(mp(-t-w-st, mp(nx, ny)));
            }
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d%d%d", &H, &N, &M);
        memset(c, -1, sizeof(c));
        memset(f, -1, sizeof(f));
        rep (i, N) rep (j, M) scanf("%d", c[i+1]+j+1);
        rep (i, N) rep (j, M) scanf("%d", f[i+1]+j+1);
        printf("Case #%d: %.6f\n", _q+1, solve()/10.0);
    }
    return 0;
}
