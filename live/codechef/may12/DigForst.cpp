#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int N, x[128], ok[128];
vector<int> g[128];
int dp[128*3*4*7*8];

int make(int at, int g3, int g4, int g7, int f) {
    g3 = (g3 * 10 + x[at]) % 3;
    g4 = (g4 * 10 + x[at]) % 4;
    g7 = (g7 * 10 + x[at]) % 7;
    if (x[at] == 3 || x[at] == 6) f |= 1;
    if (x[at] == 4) f |= 2;
    if (x[at] == 7) f |= 4;
    return (((at*3 + g3)*4 + g4)*7 + g7)*8 + f;
}

bool goal(int at, int g3, int g4, int g7, int f) {
    if (at != N-1) return false;
    if ((f&1) && g3) return false;
    if ((f&2) && g4) return false;
    if ((f&4) && g7) return false;
    return true;
}

int solve() {
    rep (i, N) ok[i] = true;
    rep (i, N) {
        if (x[N-1] % 2 != 0 && x[i] % 2 == 0) ok[i] = false;
        if (x[N-1] % 5 != 0 && x[i] % 5 == 0) ok[i] = false;
    }
    if (!ok[0]) return -1;
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, int> > q;
    q.push(mp(-x[0], make(0, 0, 0, 0, 0)));
    while (!q.empty()) {
        const pair<int, int> vx = q.top();
        q.pop();
        const int cur = vx.second;
        if (dp[cur] != -1) continue;
        dp[cur] = -vx.first;
        const int at = cur / (3*4*7*8);
        const int g3 = cur / (4*7*8) % 3;
        const int g4 = cur / (7*8) % 4;
        const int g7 = cur / 8 % 7;
        const int f = cur % 8;
        if (goal(at, g3, g4, g7, f)) return -vx.first;
        rep (i, g[at].size()) {
            const int to = g[at][i];
            if (!ok[to]) continue;
            const int nxt = make(to, g3, g4, g7, f);
            if (dp[nxt] == -1) {
                q.push(mp(vx.first-x[to], nxt));
            }
        }
    }
    return -1;
}

int main() {
    for (;;) {
        rep (i, 128) g[i].clear();
        scanf("%d", &N);
        if (N == 0) return 0;
        rep (i, N) scanf("%d", x+i);
        rep (i, N) rep (j, N) {
            int has;
            scanf("%d", &has);
            if (has) g[i].push_back(j);
        }
        printf("%d\n", solve());
    }
}
