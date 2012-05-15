#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M, f[1024][1024], dp[1024][1024];

int solve() {
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, pair<int, int> > > q;
    q.push(mp(-f[1][1], mp(1, 1)));
    while (!q.empty()) {
        pair<int, pair<int, int> > vv(q.top());
        q.pop();
        const int t = -vv.first;
        const int x = vv.second.first;
        const int y = vv.second.second;
        if (dp[x][y] != -1) continue;
        dp[x][y] = t;
        if (x == N && y == M) return t;
        rep (d, 4) {
            const int nx = x + dx[d], ny = y + dy[d];
            if (f[nx][ny] != -1 && dp[nx][ny] == -1) {
                q.push(mp(-t-f[nx][ny], mp(nx, ny)));
            }
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        memset(f, -1, sizeof(f));
        rep (i, N) rep (j, M) scanf("%d", f[i+1]+j+1);
        printf("%d\n", solve());
    }
    return 0;
}
