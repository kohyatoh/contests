#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
using namespace std;
const int INF = 1<<28;

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

int dp[128];

int solve(const Graph<int>& g, int s) {
    memset(dp, -1, sizeof(dp));
    typedef pair<int, int> T;
    priority_queue<T> q;
    q.push(mp(0, s));
    while(!q.empty()) {
        T vv(q.top());
        q.pop();
        const int cw(-vv.first);
        const int at = vv.second;
        if(dp[at]!=-1) continue;
        dp[at] = cw;
        for(int x=g.head[at]; x!=-1; x=g.es[x].next) {
            const Edge<int>& e = g.es[x];
            if(dp[e.v]==-1) q.push(mp(-cw-e.w, e.v));
        }
    }
    int ans = 0;
    rep(i, g.n) {
        if(dp[i]==-1) return INF;
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        Graph<int> g(n);
        rep(i, n) {
            int m;
            scanf("%d", &m);
            rep(j, m) {
                int v, w;
                scanf("%d%d", &v, &w);
                v--;
                g.add(Edge<int>(i, v, w));
            }
        }
        g.reindex();
        int ans = INF, ansi = -1;
        rep(i, n) {
            const int a = solve(g, i);
            if(ans>a) ans = a, ansi = i;
        }
        printf("%d %d\n", ansi+1, ans);
    }
}
