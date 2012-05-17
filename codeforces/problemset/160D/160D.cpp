#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fst first
#define snd second

#define NUM (200000)

struct unionset {
    int ud[NUM];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int n, m, as[NUM], bs[NUM], ans[NUM];
pair<int, int> es[NUM];
vector<pair<int, int> > g[NUM];
int q, ord[NUM];

int rec(int at, int pre) {
    ord[at] = q++;
    int h = ord[at];
    rep (i, g[at].size()) {
        const int to = g[at][i].fst;
        if (to == pre) continue;
        int th = ord[to];
        if (th == -1) {
            th = rec(to, at);
            if (ord[at] < th) ans[g[at][i].snd] = 1;
        }
        h = min(h, th);
    }
    return h;
}

const char *msg[] = { "at least one", "any", "none" };

int main() {
    us.init();
    memset(ord, -1, sizeof(ord));
    scanf("%d%d", &n, &m);
    rep (i, m) {
        scanf("%d%d%d", as+i, bs+i, &es[i].fst);
        as[i]--, bs[i]--;
        es[i].snd = i;
    }
    sort(es, es+m);
    int cur = 0;
    while (cur < m) {
        int nxt = cur;
        while (nxt < m && es[cur].fst == es[nxt].fst) nxt++;
        vector<int> v;
        for (int i = cur; i < nxt; i++) {
            const int ix = es[i].snd;
            const int a = us.root(as[ix]), b = us.root(bs[ix]);
            if (a == b) ans[ix] = 2;
            else {
                v.push_back(a);
                v.push_back(b);
                g[a].push_back(mp(b, ix));
                g[b].push_back(mp(a, ix));
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        rep (i, v.size()) if (ord[v[i]] == -1) {
            q = 0;
            rec(v[i], -1);
        }
        rep (i, v.size()) {
            const int ix = v[i];
            sort(g[ix].begin(), g[ix].end());
            rep (j, g[ix].size()-1) {
                if (g[ix][j].fst == g[ix][j+1].fst) {
                    ans[g[ix][j].snd] = ans[g[ix][j+1].snd] = 0;
                }
            }
            ord[ix] = -1;
            g[ix].clear();
        }
        for (int i = cur; i < nxt; i++) {
            const int a = as[es[i].snd], b = bs[es[i].snd];
            us.set(a, b);
        }
        cur = nxt;
    }
    rep (i, m) puts(msg[ans[i]]);
    return 0;
}
