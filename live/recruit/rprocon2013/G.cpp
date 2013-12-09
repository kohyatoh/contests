#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

struct unionset {
    int ud[50000];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };
int w, h, f[128][128], g[128][128];
map<int, int> co[32];
int m;
vector<pair<int, pair<int, int> > > es;

void add(int a, int b, int c) {
    if (co[a].count(b) == 0) {
        co[a][b] = c;
    }
    else {
        co[a][b] = min(co[a][b], c);
    }
}

void draw(int x, int y, int c, int t) {
    if (f[x][y] != c) return ;
    if (g[x][y] == t) return ;
    g[x][y] = t;
    rep (d, 4) {
        draw(x+dx[d], y+dy[d], c, t);
    }
}

Int solve() {
    // node
//    printf("node\n");
    memset(g, -1, sizeof(g));
    m = 0;
    rep (i, w+2) rep (j, h+2) {
        if (f[i][j] != -1 && g[i][j] == -1) {
            draw(i, j, f[i][j], m++);
        }
    }
    // edge
//    printf("edge\n");
    es.clear();
    rep (i, w+2) rep (j, h+2) if (g[i][j] != -1) {
        rep (d, 4) {
            const int x = i + dx[d];
            const int y = j + dy[d];
            if (g[i][j] != g[x][y] && g[x][y] != -1) {
                const int p = f[x][y];
                const int q = f[i][j];
                if (co[p].count(q)) {
                    es.push_back(mp(co[p][q], mp(g[i][j], g[x][y])));
                }
            }
        }
    }
    // mst
//    printf("mst\n");
    us.init();
    sort(es.begin(), es.end());
    Int ans = 0;
    rep (i, es.size()) {
        if (!us.same(es[i].second.first, es[i].second.second)) {
            us.set(es[i].second.first, es[i].second.second);
            ans += es[i].first;
        }
    }
    if (us.size(0) < m) return -1;
    return ans;
}

int main() {
    string buf;
    getline(cin, buf);
    const int T = atoi(buf.c_str());
    rep (_, T) {
        getline(cin, buf);
        sscanf(buf.c_str(), "%d%d", &h, &w);
        memset(f, -1, sizeof(f));
        rep (i, w) {
            getline(cin, buf);
            rep (j, h) f[i+1][j+1] = buf[j] == ' ' ? -1 : buf[j]-'A';
        }
//        rep (i, w+2) {
//            rep (j, h+2) printf("%d ", f[i][j]);
//            printf("\n");
//        }
        getline(cin, buf);
        const int n = atoi(buf.c_str());
        rep (i, 32) co[i].clear();
        rep (i, n) {
            getline(cin, buf);
            int c;
            char a, b;
            sscanf(buf.c_str(), "%d %c %c", &c, &a, &b);
            add(a-'A', b-'A', c);
            add(b-'A', a-'A', c);
        }
        const Int ans = solve();
        if (ans == -1) puts("IMPOSSIBLE");
        else cout << ans << endl;
    }
    return 0;
}
