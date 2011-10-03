#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INF (1LL<<60)
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

struct SCCG {
    static const int N=500000;
    int n, E, on, color[N], order[N];
    int ghead[N];
    vector<int> gu, gv, gnext;
    int hhead[N];
    vector<int> hu, hv, hnext;
    vector<int> cost;
    void init(int _n) {
        n=_n, E=0;
        memset(ghead, -1, sizeof(ghead));
        memset(hhead, -1, sizeof(hhead));
    }
    void add_edge(int _u, int _v, int _c) {
        gu.push_back(_u); gv.push_back(_v);
        gnext.push_back(ghead[gu[E]]); ghead[gu[E]]=E;
        hu.push_back(_v); hv.push_back(_u);
        hnext.push_back(hhead[hu[E]]); hhead[hu[E]]=E;
        cost.push_back(_c);
        E++;
    }
    void scc_visit_1(int at, int col) {
        if(color[at]>=0) return ;
        color[at]=col;
        for(int x=ghead[at]; x!=-1; x=gnext[x]) scc_visit_1(gv[x], col);
        order[on++]=at;
    }
    void scc_visit_2(int at, int col) {
        if(color[at]>=0) return ;
        color[at]=col;
        for(int x=hhead[at]; x!=-1; x=hnext[x]) scc_visit_2(hv[x], col);
    }
    void scc() {
        on=0;
        memset(color, -1, sizeof(color));
        rep(i, n) scc_visit_1(i, i);
        memset(color, -1, sizeof(color));
        rep(i, n) scc_visit_2(order[n-1-i], i);
    }
} g;

int N, M;
string fs[128], bs[128];
vector<int> fw[128], bw[128], xs;
int is_e[500000], sz[500000], loop[500000];
Int dp[500000];

inline int to_ix(int l, int r, int d, int c) { return ((l*128+r)*2+d)*16+c; }
inline int of(int l, int r, int d, int c) {
    return lower_bound(xs.begin(), xs.end(), to_ix(l, r, d, c)) - xs.begin();
}
void ae(int u, int v, int w) {
    if(u==v) loop[u] = 1;
    else g.add_edge(u, v, w);
}

int main() {
    char buf[16];
    scanf("%d%d", &N, &M);
    rep(i, N) {
        scanf("%s", buf);
        fs[i] = bs[i] = buf;
        reverse(bs[i].begin(), bs[i].end());
    }
    rep(_, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        fw[x].push_back(y);
        bw[y].push_back(x);
    }
    xs.push_back(-1); // starting point
    rep(l, N) rep(r, N) {
        rep(i, fs[l].size()+1) xs.push_back(to_ix(l, r, 0, i));
        is_e[xs.size()-1] = 1;
        rep(i, fs[r].size()+1) xs.push_back(to_ix(l, r, 1, i));
        is_e[xs.size()-1] = 1;
    }
    g.init(xs.size());
    rep(i, N) rep(j, fs[i].size()+1) {
        const unsigned L = fs[i].size()-j;
        if(strncmp(fs[i].c_str(), bs[i].c_str()+j, L)==0) {
            ae(0, of(i, i, 1, L), L);
        }
        if(strncmp(bs[i].c_str(), fs[i].c_str()+j, L)==0) {
            ae(0, of(i, i, 0, L), L);
        }
    }
    rep(l, N) rep(r, N) {
        rep(i, fs[l].size()+1) {
            const int ix = of(l, r, 0, i);
            rep(j, fw[r].size()) {
                const int k = fw[r][j];
                const unsigned L = min(fs[l].size()-i, fs[k].size());
                if(strncmp(bs[l].c_str()+i, fs[k].c_str(), L)) continue;
                if(L<fs[l].size()-i) ae(ix, of(l, k, 0, i+L), L*2);
                else if(L<bs[k].size()) ae(ix, of(l, k, 1, L), L*2);
                else {
                    ae(ix, of(l, k, 0, fs[l].size()), L*2);
                    ae(ix, of(l, k, 1, fs[k].size()), L*2);
                }
            }
        }
        rep(i, fs[r].size()+1) {
            const int ix = of(l, r, 1, i);
            rep(j, bw[l].size()) {
                const int k = bw[l][j];
                const unsigned L = min(fs[r].size()-i, fs[k].size());
                if(strncmp(fs[r].c_str()+i, bs[k].c_str(), L)) continue;
                if(L<fs[r].size()-i) ae(ix, of(k, r, 1, i+L), L*2);
                else if(L<bs[k].size()) ae(ix, of(k, r, 0, L), L*2);
                else {
                    ae(ix, of(k, r, 0, fs[k].size()), L*2);
                    ae(ix, of(k, r, 1, fs[r].size()), L*2);
                }
            }
        }
    }
    g.scc();
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    rep(i, xs.size()) sz[g.color[i]]++;
    rep(i, xs.size()) if(sz[g.color[i]]>1) loop[i] = 1;
    rep(i, xs.size()) {
        const int ix = g.order[xs.size()-1-i];
        if(dp[ix]==-1) continue;
        for(int x=g.ghead[ix]; x!=-1; x=g.gnext[x]) {
            const Int k = !loop[ix] && dp[ix]<INF ?  dp[ix]+g.cost[x] : INF;
            dp[g.gv[x]] = max(dp[g.gv[x]], k);
        }
    }
    Int ans = 0;
    rep(i, xs.size()) if(is_e[i]) ans = max(ans, dp[i]);
    if(ans==INF) ans = -1;
    cout << ans << endl;
    return 0;
}
