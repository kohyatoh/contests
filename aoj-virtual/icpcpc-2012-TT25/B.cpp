#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int of[6][4] = {
    { 2, 4, 3, 1 },
    { 1, 0, 1, 5 },
    { 5, 2, 0, 2 },
    { 0, 3, 5, 3 },
    { 4, 5, 4, 0 },
    { 3, 1, 2, 4 },
};

void next(string &buf) {
    buf.clear();
    getline(cin, buf);
    while (buf.size() && isspace(buf[buf.size()-1])) buf.resize(buf.size()-1);
}

struct S {
    int x, y, t;
    S() {}
    S(int x, int y, int t) : x(x), y(y), t(t) {}
};
bool operator<(const S& l, const S& r) {
    if (l.x != r.x) return l.x < r.x;
    if (l.y != r.y) return l.y < r.y;
    return l.t < r.t;
}

int n, m, sx, sy, tx, ty;
int w[16][16][4];

int solve() {
    set<S> vis;
    queue<pair<int, S> > q;
    q.push(mp(0, S(sx, sy, 0)));
    while (!q.empty()) {
        const pair<int, S> vv = q.front();
        q.pop();
        const int di = vv.first;
        const S cur = vv.second;
        if (vis.count(cur)) continue;
        vis.insert(cur);
        if (cur.x == tx && cur.y == ty && cur.t == 0) return di;
        rep (d, 4) if (w[cur.x][cur.y][d] == 0) {
            q.push(mp(di+1, S(cur.x+dx[d], cur.y+dy[d], of[cur.t][d])));
        }
    }
    return -1;
}

int main() {
    string buf;
    next(buf);
    const int T = atoi(buf.c_str());
    next(buf);
    rep (_q, T) {
        next(buf);
        sscanf(buf.c_str(), "%d%d", &n, &m);
        next(buf);
        sscanf(buf.c_str(), "%d%d", &sx, &sy);
        next(buf);
        sscanf(buf.c_str(), "%d%d", &tx, &ty);
        next(buf);
        memset(w, 0, sizeof(w));
        for (int i = 1; i <= m; i++) {
            w[1][i][2] = w[n][i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            w[i][1][3] = w[i][m][1] = 1;
        }
        while (buf != "") {
            if (buf == "v") {
                for (;;) {
                    next(buf);
                    if (buf.size() <= 1) break;
                    int x, y;
                    sscanf(buf.c_str(), "%d%d", &x, &y);
                    w[x][y][0] = w[x+1][y][2] = 1;
                }
            }
            else if (buf == "h") {
                for (;;) {
                    next(buf);
                    if (buf.size() <= 1) break;
                    int x, y;
                    sscanf(buf.c_str(), "%d%d", &x, &y);
                    w[x][y][1] = w[x][y+1][3] = 1;
                }
            }
        }
        if (_q) puts("");
        const int ans = solve();
        if (ans == -1) puts("No solution");
        else printf("%d\n", ans);
    }
    return 0;
}
