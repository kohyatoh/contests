#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define F(x, y, d) while (f[x+dx[d]][y+dy[d]] != '#') x+=dx[d], y+=dy[d]
inline int h(int x, int y, int d) { return (x<<8) | (y<<2) | d; }
inline int h(int x1, int y1, int d1, int x2, int y2, int d2) {
    return (h(x1, y1, d1) << 16) | h(x2, y2, d2);
}

int H, W;
char f[16][64], h1[16][64][4];
int sx, sy, sd, tx, ty, td;
std::unordered_set<int> h2;

bool reach(int x, int y, int d) {
    F(x, y, d);
    if (x == tx && y == ty) return true;
    if (h1[x][y][d]) return false;
    h1[x][y][d] = 1;
    if (reach(x, y, (d+1)%4)) return true;
    if (reach(x, y, (d+3)%4)) return true;
    return false;
}

bool acc(int cx, int cy, int cd, int x, int y, int d) {
    if (f[x+dx[d]][y+dy[d]] != '#') return false;
    F(cx, cy, cd);
    const bool p = cx == tx && cy == ty && d == td;
    while (f[x][y] != '#') {
        if (!h2.insert(h(cx, cy, cd, x, y, d)).second) break;
        if (p && x == tx && y == ty) return true;
        if (acc(cx, cy, (cd+1)%4, x, y, (d+1)%4)) return true;
        if (acc(cx, cy, (cd+3)%4, x, y, (d+3)%4)) return true;
        x -= dx[d], y -= dy[d];
    }
    return false;
}

void solve() {
    memset(h1, 0, sizeof(h1));
    rep (i, H) rep (j, W) if (f[i][j] == 'K') {
        f[i][j] = '.';
        rep (d, 4) if (f[i+dx[d]][j+dy[d]] != '#') sx = i, sy = j, sd = d;
    }
    rep (i, H) rep (j, W) if (f[i][j] == 'M') {
        f[i][j] = '.';
        rep (d, 4) if (f[i+dx[d]][j+dy[d]] != '#') tx = i, ty = j, td = d;
    }
    if (!reach(sx, sy, sd)) puts("He cannot bring tea to his master.");
    else {
        h2.clear();
        rep (d, 4) if (acc(sx, sy, sd, sx, sy, d)) {
            puts("He can accomplish his mission.");
            return ;
        }
        puts("He cannot return to the kitchen.");
    }
}

int main() {
    char buf[80];
    for (;;) {
        fgets(buf, 80, stdin);
        sscanf(buf, "%d%d", &W, &H);
        if (W == 0) return 0;
        rep (i, H) {
            fgets(buf, 80, stdin);
            memcpy(f[i], buf, W);
        }
        solve();
    }
}
