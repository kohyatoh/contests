#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
vector<int> px, py, qx, qy;
int f[2048][2048], v[2048][2048];

int solve() {
    memset(f, 0, sizeof(f));
    memset(v, 0, sizeof(v));
    rep (i, n) {
        const int j = (i+1) % n;
        if (px[i] == px[j]) {
            const int x = px[i], d = py[i] < py[j] ? 1 : -1;
            for (int y = py[i]; y != py[j]; y += d) f[x][y] = 1;
        }
        else {
            const int y = py[i], d = px[i] < px[j] ? 1 : -1;
            for (int x = px[i]; x != px[j]; x += d) f[x][y] = 1;
        }
    }
    queue<pair<int, pair<int, int> > > q;
    rep (i, m) {
        const int j = (i+1) % m;
        if (qx[i] == qx[j]) {
            const int x = qx[i], d = qy[i] < qy[j] ? 1 : -1;
            for (int y = qy[i]; y != qy[j]; y += d) {
                if (f[x][y]) return 0;
                v[x][y] = 1;
                q.push(mp(0, mp(x, y)));
            }
        }
        else {
            const int y = qy[i], d = qx[i] < qx[j] ? 1 : -1;
            for (int x = qx[i]; x != qx[j]; x += d) {
                if (f[x][y]) return 0;
                v[x][y] = 1;
                q.push(mp(0, mp(x, y)));
            }
        }
    }
    while (!q.empty()) {
        const pair<int, pair<int, int> > vv = q.front();
        q.pop();
        const int di = vv.first;
        const int x = vv.second.first, y = vv.second.second;
        rep (d, 4) {
            const int nx = x + dx[d], ny = y + dy[d];
            if (0 <= nx && nx <= 2000 && 0 <= ny && ny <= 2000) {
                if (!v[nx][ny]) {
                    if (f[nx][ny]) return di+1;
                    v[nx][ny] = 1;
                    q.push(mp(di+1, mp(nx, ny)));
                }
            }
        }
    }
    return -1;
}

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        px.clear(), py.clear(), qx.clear(), qy.clear();
        rep (i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            px.push_back(x), py.push_back(y);
        }
        scanf("%d", &m);
        rep (i, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            qx.push_back(x), qy.push_back(y);
        }
        printf("%d\n", solve());
    }
    return 0;
}
