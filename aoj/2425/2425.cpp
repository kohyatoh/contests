#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int dx[6] = { 0, 1, 1, 0, -1, -1 };
const int dy[2][6] = {
    { 1, 0, -1, -1, -1, 0 },
    { 1, 1, 0, -1, 0, 1 },
};

struct ST {
    int x, y, t, a;
    ST() {}
    ST(int x, int y, int t, int a) : x(x), y(y), t(t), a(a) {}
};

#define B (128)
int sx, sy, gx, gy, lx, ly;
int f[B*2][B*2], dp[B*2][B*2][6];

int solve() {
    memset(dp, -1, sizeof(dp));
    deque<ST> q;
    q.push_back(ST(sx, sy, 0, 0));
    while (!q.empty()) {
        ST cur = q.front();
        q.pop_front();
        const int x = cur.x, y = cur.y, t = cur.t;
        if (dp[B+x][B+y][t] != -1) continue;
        dp[B+x][B+y][t] = cur.a;
        if (x == gx && y == gy) return cur.a;
        rep (d, 6) {
            const int nx = x+dx[d], ny = y+dy[x&1][d];
            if (abs(nx) > lx || abs(ny) > ly) continue;
            if (f[B+nx][B+ny]) continue;
            if (d == abs(x*y*t)%6) q.push_front(ST(nx, ny, (t+1)%6, cur.a));
            else q.push_back(ST(nx, ny, (t+1)%6, cur.a+1));
        }
        q.push_back(ST(x, y, (t+1)%6, cur.a+1));
    }
    return -1;
}

int main() {
    scanf("%d%d%d%d", &sx, &sy, &gx, &gy);
    int n;
    scanf("%d", &n);
    rep (_, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        f[B+x][B+y] = 1;
    }
    scanf("%d%d", &lx, &ly);
    printf("%d\n", solve());
    return 0;
}
