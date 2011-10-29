#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

struct Edge {
    int u, v;
    int next;
    Edge() {}
    Edge(int _u, int _v) : u(_u), v(_v) {}
};

struct Graph {
    int n, m;
    vector<Edge> es;
    vector<int> head;
    Graph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(const Edge& e) {
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

int n, C, col[200], h[200], use[200];

void draw(const Graph& g, int at, int c) {
    if(col[at]!=-1) return ;
    col[at] = c;
    for(int x=g.head[at]; x!=-1; x=g.es[x].next) {
        draw(g, g.es[x].v, c);
    }
}

bool height(const Graph& g, int ro) {
    rep(i, n) if(col[i]==col[ro]) h[i] = -1;
    queue<int> q;
    q.push(ro);
    h[ro] = 1;
    while(!q.empty()) {
        const int at = q.front();
        q.pop();
        for(int x=g.head[at]; x!=-1; x=g.es[x].next) {
            const int v = g.es[x].v;
            if(h[v]==-1) {
                h[v] = h[at]+1;
                q.push(v);
            }
            else if(h[v]!=h[at]-1 && h[v]!=h[at]+1) {
                return false;
            }
        }
    }
    return true;
}

int solve(const Graph& g) {
    rep(i, n) if(use[i]==0) return -1;
    int cur = 0;
    rep(k, C) {
        int ans = -1, ansi = -1;
        rep(i, n) if(col[i]==k) {
            if(height(g, i)) {
                int z = 0;
                rep(j, n) if(col[j]==k) z = max(z, h[j]);
                if(ans<z) ans=z, ansi=i;
            }
        }
        if(ans==-1) return -1;
        height(g, ansi);
        if(k>0) cur = 50-ans;
        rep(i, n) if(col[i]==k) h[i] += cur;
        cur += ans;
    }
    if(cur<1 || cur>50) return -1;
    return cur-1;
}

int main() {
    int m;
    scanf("%d%d", &m, &n);
    Graph g(n);
    rep(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g.add(Edge(u, v));
        g.add(Edge(v, u));
        use[u] = use[v] = 1;
    }
    memset(col, -1, sizeof(col));
    rep(i, n) if(col[i]==-1) draw(g, i, C++);
    const int ans = solve(g);
    printf("%d\n", ans);
    if(ans!=-1) {
        rep(i, n) printf("%d%c", h[i], i<n-1 ? ' ' : '\n');
    }
    return 0;
}


