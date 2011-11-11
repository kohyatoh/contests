#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)


template<class W>
struct Edge {
    int u, v;
    W capa, flow;
    int next, rev;
    Edge(int u, int v, const W& c, const W& f)
        : u(u), v(v), capa(c), flow(f) {}
    W res() const { return capa - flow; }
};

template<class E>
struct Graph {
    int n, m;
    vector<E> es;
    vector<int> head;
    Graph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(const E& e) {
        es.push_back(e);
        es[m].next = head[e.u];
        head[e.u] = m;
        m++;
    }
    void add_rev(const E& e, const E& r) {
        assert(e.u == r.v && e.v == r.u);
        add(e);
        add(r);
        es[m-2].rev = m-1;
        es[m-1].rev = m-2;
    }
    void reindex() {
        fill(head.begin(), head.end(), -1);
        for(int i=m-1; i>=0; i--) {
            es[i].next = head[es[i].u];
            head[es[i].u] = i;
        }
    }
};

struct MaxFlow {
    typedef int capa_t;
    typedef Edge<capa_t> E;
    Graph<E> g;
    vector<int> prev;
    MaxFlow(int n) : g(n), prev(n) {}
    void add_edge(int u, int v, int ca) {
        g.add_rev(E(u, v, ca, 0), E(v, u, 0, 0));
    }
    int pour(int s, int t, capa_t F=1<<30) {
        capa_t total = 0;
        while(total < F) {
            fill(prev.begin(), prev.end(), -1);
            queue<int> q;
            prev[s] = g.m;
            q.push(s);
            while(!q.empty() && prev[t]<0) {
                const int u = q.front();
                q.pop();
                for(int x=g.head[u]; x!=-1; x=g.es[x].next) {
                    const E& e = g.es[x];
                    if(prev[e.v]<0 && e.res() > 0) {
                        prev[e.v] = x;
                        q.push(e.v);
                    }
                }
            }
            if(prev[t]<0) return total;
            capa_t inc = F-total;
            for(int at=t; prev[at]!=g.m; at=g.es[prev[at]].u) {
                const E& e = g.es[prev[at]];
                inc = min(inc, e.res());
            }
            for(int at=t; prev[at]!=g.m; at=g.es[prev[at]].u) {
                E& e = g.es[prev[at]];
                E& r = g.es[e.rev];
                e.flow += inc;
                r.flow -= inc;
            }
            total += inc;
        }
        return total;
    }
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int h, w, g[512][512];
char f[64][64];

inline int enc(int x, int y) { return x*w+y; }

int solve() {
    const int T = h*w*(h+w);
    vector<int> dr;
    rep(i, h) rep(j, w) if(f[i][j]=='D') dr.push_back(enc(i, j));
    MaxFlow mf(2+h*w+dr.size()*T);
    int c = 0;
    rep(i, h) rep(j, w) if(f[i][j]=='.') {
        mf.add_edge(0, 2+enc(i, j), 1);
        c++;
        bool ok = false;
        rep(k, dr.size()) if(g[enc(i, j)][dr[k]]<INF) ok = true;
        if(!ok) return -1;
    }
    if(c==0) return 0;
    int cur = 0;
    rep(t, T) {
        rep(k, dr.size()) {
            const int ix = 2 + w*h + k*T + t;
            mf.add_edge(ix, 1, 1);
            rep(i, h) rep(j, w) if(f[i][j]=='.' && g[enc(i, j)][dr[k]]<=t) {
                mf.add_edge(2+enc(i, j), ix, 1);
            }
        }
        cur += mf.pour(0, 1);
        if(cur==c) return t;
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &h, &w);
        rep(i, h) rep(j, w) scanf(" %c", f[i]+j);
        assert(h<=12);
        assert(w<=12);
        rep(i, 512) rep(j, 512) g[i][j] = INF;
        rep(i, 512) g[i][i] = 0;
        rep(i, h) rep(j, w) if(f[i][j]!='X') {
            rep(d, 4) {
                const int x = i+dx[d], y = j+dy[d];
                if(x<0 || x>=h || y<0 || y>=w) continue;
                if(f[x][y]!='X') g[enc(i, j)][enc(x, y)] = 1;
            }
        }
        const int n = h*w;
        rep(k, n) rep(i, n) rep(j, n) g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        const int ans = solve();
        if(ans==-1) puts("impossible");
        else printf("%d\n", ans);
    }
    return 0;
}
