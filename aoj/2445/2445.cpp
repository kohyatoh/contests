#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
typedef long long Int;
#define MOD (1000000009LL)
#define INF (1<<28)
inline void add(Int &a, Int b) { a = (a + b) % MOD; }

#define P (2000001)
Int inv[P], ft[P], ift[P];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
pair<int, int> ps[64];
Int fw[64][64];
#define D (128)
#define H (52)
int xof[2][D][D], yof[2][D][D], dt[2][D][D];
Int cnt[2][D][D][2];

Int f(int sx, int sy, int ex, int ey) {
    const int dx = ex-sx, dy = ey-sy;
    return dx >= 0 && dy >= 0 ? ft[dx+dy] * ift[dx] % MOD * ift[dy] % MOD : 0;
}

Int calc(int sx, int sy, int ex, int ey) {
    static Int dp[64][2];
    rep (i, m) dp[i][0] = 0, dp[i][1] = f(sx, sy, ps[i].fst, ps[i].snd);
    Int ans = f(sx, sy, ex, ey);
    rep (i, m) rep (t, 2) {
        const Int w = dp[i][t] * f(ps[i].fst, ps[i].snd, ex, ey);
        if (t) add(ans, MOD-w%MOD); else add(ans, w);
        for (int j = i+1; j < m; j++) add(dp[j][(t+1)%2], dp[i][t]*fw[i][j]);
    }
    return ans;
}

inline bool valid(int w, int L, int x, int y) {
    return 0 <= x && x < L && 0 <= y && y < L && dt[w][x][y] < INF;
}

void build(int w, int L) {
    queue<pair<int, int> > q;
    q.push(mp(0, 0));
    memset(dt[w], -1, sizeof(dt[0]));
    dt[w][0][0] = 0;
    rep (x, L) rep (y, L) {
        if (w == 0) xof[w][x][y] = x, yof[w][x][y] = y;
        else xof[w][x][y] = n-1-x, yof[w][x][y] = n-1-y;
    }
    rep (x, L) rep (y, L) rep (i, m) {
        if (mp(xof[w][x][y], yof[w][x][y]) == ps[i]) dt[w][x][y] = INF;
    }
    while (!q.empty()) {
        const pair<int, int> vv = q.front();
        q.pop();
        const int x = vv.fst, y = vv.snd;
        rep (d, 4) {
            const int nx = x+dx[d], ny = y+dy[d];
            if (valid(w, L, nx, ny) && dt[w][nx][ny] == -1) {
                q.push(mp(nx, ny)), dt[w][nx][ny] = dt[w][x][y] + 1;
            }
        }
    }
    rep (x, L) rep (y, L) if (dt[w][x][y] == -1) dt[w][x][y] = INF;
    vector<pair<int, pair<int, int> > > vs;
    rep (x, L) rep (y, L) if (dt[w][x][y] < INF) {
        vs.push_back(mp(dt[w][x][y], mp(x, y)));
    }
    sort(vs.begin(), vs.end());
    memset(cnt[w], 0, sizeof(cnt[0]));
    cnt[w][0][0][1] = 1;
    rep (i, vs.size()) rep (t, 2) {
        const int x = vs[i].snd.fst, y = vs[i].snd.snd;
        rep (d, 4) {
            const int nx = x+dx[d], ny = y+dy[d];
            if (valid(w, L, nx, ny) && dt[w][nx][ny] == dt[w][x][y]+1) {
                add(cnt[w][nx][ny][d/2], cnt[w][x][y][t]);
            }
        }
    }
}

int main() {
    inv[1] = 1;
    for (int i = 2; i < P; i++) inv[i] = inv[MOD%i] * (MOD - MOD/i) % MOD;
    ft[0] = ift[0] = 1;
    rep (i, P-1) ft[i+1] = (i+1)*ft[i]%MOD, ift[i+1] = inv[i+1]*ift[i]%MOD;
    scanf("%d%d", &n, &m);
    rep (i, m) scanf("%d%d", &ps[i].fst, &ps[i].snd);
    rep (i, m) ps[i].fst--, ps[i].snd--;
    sort(ps, ps+m);
    rep (i, m) rep (j, m) {
        fw[i][j] = f(ps[i].fst, ps[i].snd, ps[j].fst, ps[j].snd);
    }
    if (n < D) {
        build(0, n);
        cout << cnt[0][n-1][n-1][0] << endl;
        return 0;
    }
    build(0, H), build(1, H);
    Int ans = 0;
    int cur = INF;
    vector<pair<int, int> > vs;
    rep (i, H) rep (j, H) if (dt[0][i][j] < INF && cnt[0][i][j][1]) {
        vs.push_back(mp(i, j));
    }
    rep (i, H) rep (j, H) if (dt[1][i][j] < INF && cnt[1][i][j][1]) {
        rep (k, vs.size()) {
            const int x = vs[k].fst, y = vs[k].snd;;
            const int sum = dt[0][x][y] + dt[1][i][j] 
                + xof[1][i][j] - x + yof[1][i][j] - y;
            if (sum > cur) continue;
            const Int w = calc(x, y, xof[1][i][j], yof[1][i][j]);
            if (w == 0) continue;
            if (cur > sum) cur = sum, ans = 0;
            if (cur == sum) add(ans, cnt[0][x][y][1]*w%MOD*cnt[1][i][j][1]);
        }
    }
    cout << ans << endl;
    return 0;
}
