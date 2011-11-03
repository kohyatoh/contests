#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <bitset>
#include <queue>
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

int M, N, a[1024], b[100];
bitset<1024> cs[100];

int main() {
    scanf("%d%d", &M, &N);
    rep(i, M) scanf("%d", a+i);
    rep(i, N) {
        int m;
        scanf("%d", &m);
        rep(_, m) {
            int k;
            scanf("%d", &k);
            cs[i].set(k-1);
        }
        scanf("%d", b+i);
    }
    MaxFlow mf(128+M);
    rep(i, M) mf.add_edge(0, 128+i, a[i]);
    rep(i, N) mf.add_edge(2+i, 1, b[i]);
    rep(k, N) {
        rep(i, M) if(cs[k][i]) mf.add_edge(128+i, 2+k, INF);
        rep(i, k) {
            rep(j, M) if(cs[k][j] && cs[i][j]) {
                mf.add_edge(2+i, 2+k, INF);
                break;
            }
        }
    }
    mf.g.reindex();
    printf("%d\n", mf.pour(0, 1));
    return 0;
}
