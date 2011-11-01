#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
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
    string buf;
    for(;;) {
        getline(cin, buf);
        const int n = atoi(buf.c_str());
        if(n==0) return 0;
        UEGraph g(n);
        for(;;) {
            getline(cin, buf);
            istringstream sin(buf);
            int u, v;
            sin >> u;
            if(u==0) break;
            while(sin>>v) g.add(u-1, v-1);
        }
        ArticulationPoints ap(g);
        int ans = 0;
        rep(i, n) if(ap.count(i)>1) ans++;
        printf("%d\n", ans);
    }
}
