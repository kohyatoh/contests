#include <stdio.h>
#include <queue>
#include <set>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct S {
    int x, y, d;
    S() {}
    S(int x, int y, int d) : x(x), y(y), d(d) {}
};

bool operator<(const S& l, const S& r) {
    if (l.x != r.x) return l.x < r.x;
    if (l.y != r.y) return l.y < r.y;
    return l.d < r.d;
}

int H, W;
char f[16][64];

S forward(int x, int y, int d) {
    for (;;) {
        const int nx = x + dx[d], ny = y + dy[d];
        if (f[nx][ny] == '#') return S(x, y, d);
        x = nx, y = ny;
    }
}

#define PUSH(q, vis, s) { if (!vis.count(s)) vis.insert(s), q.push(s); }
bool reach(const S& s, const S& t) {
    set<S> vis;
    queue<S> q;
    const S st = forward(s.x, s.y, s.d);
    PUSH(q, vis, st);
    while (!q.empty()) {
        const S cur = q.front();
        q.pop();
        if (cur.x == t.x && cur.y == t.y) return true;
        int dd = 1;
        rep (_, 2) {
            const S p = forward(cur.x, cur.y, (cur.d+dd)%4);
            PUSH(q, vis, p);
            dd += 2;
        }
    }
    return false;
}

void push(queue<pair<S, S> >& q, set<pair<S, S> >& vis, const S& l, int x, int y, int d) {
    const int rd = (d+2) % 4;
    if (f[x+dx[d]][y+dy[d]] != '#') return ;
    for (;;) {
        const pair<S, S> ss(l, S(x, y, d));
        PUSH(q, vis, ss);
        const int nx = x + dx[rd], ny = y + dy[rd];
        if (f[nx][ny] == '#') break;
        x = nx, y = ny;
    }
}

bool accomplish(const S& s, const S& t) {
    set<pair<S, S> > vis;
    queue<pair<S, S> > q;
    const S st = forward(s.x, s.y, s.d);
    rep (d, 4) push(q, vis, st, s.x, s.y, d);
    while (!q.empty()) {
        const pair<S, S> vv = q.front();
        q.pop();
        const S cur = vv.first, rev = vv.second;
        if (cur.x == t.x && cur.y == t.y
                && rev.x == t.x && rev.y == t.y && rev.d == t.d) {
            return true;
        }
        int dd = 1;
        rep (_, 2) {
            push(q, vis, forward(cur.x, cur.y, (cur.d+dd)%4),
                    rev.x, rev.y, (rev.d+dd)%4);
            dd += 2;
        }
    }
    return false;
}

void solve() {
    S s(-1, -1, -1), t(-1, -1, -1);
    rep (i, H) rep (j, W) if (f[i][j] == 'K') {
        f[i][j] = '.';
        s.x = i, s.y = j;
        rep (d, 4) if (f[i+dx[d]][j+dy[d]] != '#') s.d = d;
    }
    rep (i, H) rep (j, W) if (f[i][j] == 'M') {
        f[i][j] = '.';
        t.x = i, t.y = j;
        rep (d, 4) if (f[i+dx[d]][j+dy[d]] != '#') t.d = d;
    }
    if (!reach(s, t)) puts("He cannot bring tea to his master.");
    else if (!accomplish(s, t)) puts("He cannot return to the kitchen.");
    else puts("He can accomplish his mission.");
}

int main() {
    for (;;) {
        scanf("%d%d", &W, &H);
        if (H == 0) return 0;
        rep (i, H) rep (j, W) scanf(" %c", f[i]+j);
        solve();
    }
}
