#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;
char f[512][512];
int vis[512][512];

bool can(double li) {
    memset(vis, 0, sizeof(vis));
    vector<pair<int, pair<int, int> > > q[2];
    rep (i, N) rep (j, M) if (f[i][j] == 's') {
        q[0].push_back(mp(0, mp(i, j)));
    }
    int cur = 0, nxt = 1;
    for (double t = 1; q[cur].size(); t *= 0.99) {
        rep (i, q[cur].size()) {
            const pair<int, pair<int, int> > vv(q[cur][i]);
            const int dd = vv.first;
            const int x = vv.second.first, y = vv.second.second;
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            if (f[x][y] == 'g') return true;
            if (f[x][y] == '#') continue;
            if ('0' <= f[x][y] && f[x][y] <= '9') {
                if ((f[x][y]-'0') * t < li) continue;
            }
            rep (d, 4) q[nxt].push_back(mp(dd+1, mp(x+dx[d], y+dy[d])));
        }
        swap(cur, nxt);
        q[nxt].clear();
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    memset(f, '#', sizeof(f));
    rep (i, N) rep (j, M) scanf(" %c", f[i+1]+j+1);
    N += 2;
    M += 2;
    double l = 0, r = 10;
    if (!can(l)) puts("-1");
    else {
        rep (_, 100) {
            const double mid = (l+r) / 2;
            if (can(mid)) l = mid;
            else r = mid;
        }
        printf("%.9f\n", l);
    }
    return 0;
}
