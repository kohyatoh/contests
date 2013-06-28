#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
typedef long long Int;


int n, v, as[400], bs[400];
vector<int> es[400];
vector<pair<int, pair<int, int> > > ans;
int pre[400];

void make(int st) {
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    pre[st] = st;
    q.push(st);
    while (!q.empty()) {
        const int at = q.front();
        q.pop();
        rep (i, es[at].size()) {
            const int to = es[at][i];
            if (pre[to] == -1) {
                pre[to] = at;
                q.push(to);
            }
        }
    }
}

void pour(int st, int ed, int am) {
    if (st == ed) return ;
    const int p = pre[ed];
    if (as[p] >= am) {
        ans.push_back(mp(am, mp(p, ed)));
        as[p] -= am;
        as[ed] += am;
        pour(st, p, am);
    }
    else {
        pour(st, p, am);
        ans.push_back(mp(am, mp(p, ed)));
        as[p] -= am;
        as[ed] += am;
    }
}

bool solve() {
    Int sum = 0;
    rep (i, n) sum += as[i]-bs[i];
    if (sum != 0) return 0;
    rep (i, n) if (as[i] > bs[i]) {
        make(i);
        rep (j, n) if (pre[j] != -1 && as[j] < bs[j]) {
            const int am = min(as[i] - bs[i], bs[j] - as[j]);
            if (am/2) pour(i, j, am/2);
            if (am-am/2) pour(i, j, am-am/2);
        }
    }
    rep (i, n) if (as[i] != bs[i]) return false;
    return true;
}

int main() {
    int m;
    scanf("%d%d%d", &n, &v, &m);
    rep (i, n) scanf("%d", as+i);
    rep (i, n) scanf("%d", bs+i);
    rep (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        es[u].push_back(v);
        es[v].push_back(u);
    }
    if (solve()) {
        printf("%d\n", (int)ans.size());
        rep (i, ans.size()) {
            printf("%d %d %d\n", ans[i].snd.fst+1, ans[i].snd.snd+1,
                    ans[i].fst);
        }
    }
    else {
        puts("NO");
    }
    return 0;
}
