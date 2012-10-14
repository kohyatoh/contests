#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int N, p[200000], vis[200000];

int visit(int at) {
    if (vis[at]) return -1;
    vis[at] = 1;
    if (p[at] == 0) return at;
    return visit(at+p[at]);
}

int solve() {
    queue<pair<int, int> > q;
    q.push(mp(0, 0));
    while (!q.empty()) {
        pair<int, int> vv = q.front();
        q.pop();
        if (vv.second == N-1) return vv.first;
        rep (i, 6) {
            int t = visit(vv.second+1+i);
            if (t != -1) q.push(mp(vv.first+1, t));
        }
    }
    return -1;
}

int main() {
    scanf("%d", &N);
    rep (i, N) scanf("%d", p+i);
    printf("%d\n", solve());
    return 0;
}
