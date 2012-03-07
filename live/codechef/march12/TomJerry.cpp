#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
#define INF (1<<28)
typedef pair<int, int> loc;

const int dx[4] = { -1, 0, 0, 1 };
const int dy[4] = { 0, 1, -1, 0 };

int M, N, tx, ty;
char f[64][64];
int from[64][64], path[64][64], ox[10], oy[10];

void mark(int x, int y, int z) {
    while (z > 0) {
        if (z < 10) ox[z] = x, oy[z] = y;
        path[x][y] = z--;
        const int d = 3-from[x][y];
        x += dx[d];
        y += dy[d];
    }
    ox[0] = x, oy[0] = y;
    path[x][y] = z;
}

int calc(int sx, int sy) {
    memset(from, -1, sizeof(from));
    memset(path, -1, sizeof(path));
    vector<loc> q[2];
    assert(f[sx][sy] == '.');
    from[sx][sy] = -2;
    q[0].push_back(mp(sx, sy));
    for (int k = 0; q[k%2].size(); k++) {
        const int cur = k%2, nxt = 1-cur;
        rep (i, q[cur].size()) {
            const int x = q[cur][i].fst, y = q[cur][i].snd;
            rep (d, 4) {
                const int nx = x+dx[d], ny = y+dy[d];
                if (f[nx][ny] != '#' && from[nx][ny] == -1) {
                    from[nx][ny] = d;
                    if (f[nx][ny] == '0') {
                        mark(nx, ny, k+1);
                        return k+1;
                    }
                    q[nxt].push_back(mp(nx, ny));
                }
            }
        }
        q[cur].clear();
    }
    return INF;
}

vector<loc> solve_far() {
    vector<loc> ans;
    for (int k = 3; k < 5; k++) rep (d, 4) {
        const int x = ox[k]+dx[d], y = oy[k]+dy[d];
        if (f[x][y] == '.' && path[x][y] == -1) {
            ans.push_back(mp(x, y));
        }
    }
    rep (i, M) rep (j, N) if (f[i][j] == '.' && path[i][j] == -1) {
        if (ans.size() < 4) ans.push_back(mp(i, j));
    }
    ans.push_back(mp(ox[5], oy[5]));
    if (ans.size() == 5) {
        ans.push_back(mp(ox[2], oy[2]));
    }
    return ans;
}

vector<loc> solve() {
    calc(tx, ty);
    /*
    rep (i, M) {
        rep (j, N) {
            if (path[i][j] < 0) printf(".");
            else printf("%d", path[i][j]);
        }
        printf("\n");
    }
    */
    vector<loc> ans;
    while (ans.size() <= 200) {
        if (f[tx][ty] == '0') break;
        const int dist = calc(tx, ty);
        if (dist == INF || dist <= 1) break;
        if (dist >= 6) {
            vector<loc> v = solve_far();
            rep (i, v.size()) ans.push_back(v[i]);
            break;
        }
        else {
            const int x = ox[dist-1], y = oy[dist-1];
            ans.push_back(mp(x, y));
            f[x][y] = '#';
            int d = calc(tx, ty);
            if (d == INF) break;
            else {
                tx = ox[1];
                ty = oy[1];
            }
        }
    }
    return ans;
}

int main() {
    memset(f, '#', sizeof(f));
    scanf("%d%d", &M, &N);
    rep (i, M) rep (j, N) scanf(" %c", f[i+1]+j+1);
    M += 2, N += 2;
    rep (i, M) rep (j, N) if (f[i][j] == '*') tx = i, ty = j, f[i][j] = '.';
    vector<loc> ans = solve();
    if (ans.size() > 200) ans.clear();
    printf("%d\n", (int)ans.size());
    rep (i, ans.size()) printf("%d %d\n", ans[i].fst, ans[i].snd);
    return 0;
}
