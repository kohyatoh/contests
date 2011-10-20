#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (1<<28)

template<class W>
struct Edge {
    int u, v;
    W w;
    int next;
    Edge() {}
    Edge(int _u, int _v, const W& _w) : u(_u), v(_v), w(_w) {}

    Edge reverse() const { return Edge<W>(v, u, w); }
};

template<class W>
struct Graph {
    int n, m;
    vector<Edge<W> > es;
    vector<int> head;
    Graph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(const Edge<W>& e) {
        es.push_back(e);
        es[m].next = head[e.u];
        head[e.u] = m;
        m++;
    }
    void reindex() {
        fill(head.begin(), head.end(), -1);
        for(int i=m-1; i>=0; i--) {
            es[i].next = head[es[i].u];
            head[es[i].u] = i;
        }
    }
};

template<class W>
struct UGraph : public Graph<W> {
    UGraph(int n) : Graph<W>(n) {}
    void add(const Edge<W>& e) {
        Graph<W>::add(e);
        Graph<W>::add(e.reverse());
    }
};

/** Dijkstra's shortest path algorithm */
template<class W>
W dijkstra(const Graph<W>& g, int s, int t) {
    typedef pair<W, int> T;
    priority_queue<T> q;
    set<int> vis;
    q.push(mp(INF, s));
    while(!q.empty()) {
        T vv(q.top());
        q.pop();
        const W cw(vv.first);
        const int at = vv.second;
        if(vis.count(at)) continue;
        vis.insert(at);
        if(at==t) return cw;
        for(int x=g.head[at]; x!=-1; x=g.es[x].next) {
            const Edge<W>& e = g.es[x];
            if(vis.count(e.v)==0) q.push(mp(min(cw, e.w), e.v));
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        int n, m;
        scanf("%d%d", &n, &m);
        UGraph<int> g(n);
        rep(_, m) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--, v--;
            g.add(Edge<int>(u, v, w));
        }
        g.reindex();
        printf("Scenario #%d:\n", _q+1);
        printf("%d\n", dijkstra(g, 0, n-1));
        printf("\n");
    }
    return 0;
}

