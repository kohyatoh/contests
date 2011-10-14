#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define pb push_back

/** Edge-based graph (directed or undirected) */
struct EGraph {
    int n, m;
    vector<int> head, u, v, next;
    EGraph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(int _u, int _v) {
        u.pb(_u); v.pb(_v); next.pb(head[_u]); head[_u] = m++;
    }
};

/** Edge-based undirected graph */
struct UEGraph : public EGraph {
    UEGraph(int n) : EGraph(n) {}
    void add(int u, int v) { EGraph::add(u, v); EGraph::add(v, u); }
};

class ArticulationPoints {
    // cnt[i] -> the number of disconnected graphs after node i is removed.
    const UEGraph& g;
    vector<int> cnt, low;
    void dfs(int u, int d) {
        low[u] = d;
        for(int x=g.head[u]; x!=-1; x=g.next[x]) {
            const int v = g.v[x];
            if(low[v]==-1) {
                dfs(v, d+1);
                if(low[v]>=d) cnt[u]++;
            }
        }
        for(int x=g.head[u]; x!=-1; x=g.next[x]) {
            low[u] = min(low[u], low[g.v[x]]);
        }
        if(d) cnt[u]++;
    }
public:
    ArticulationPoints(const UEGraph& g)
        : g(g), cnt(g.n), low(g.n, -1) {
        rep(i, g.n) if(low[i]==-1) {
            dfs(i, 0);
        }
    }
    int count(int i) { return cnt[i]; }
};

int main() {
    for(int _q=0;; _q++) {
        UEGraph g(1000);
        for(;;) {
            int a, b;
            scanf("%d", &a);
            if(a==0) break;
            scanf("%d", &b);
            g.add(a-1, b-1);
        }
        if(g.m==0) return 0;
        ArticulationPoints ap(g);
        printf("Network #%d\n", _q+1);
        int c = 0;
        rep(i, g.n) if(ap.count(i)>1) {
            printf("  SPF node %d leaves %d subnets\n", i+1, ap.count(i));
            c++;
        }
        if(c==0) printf("  No SPF nodes\n");
        puts("");
    }
}

