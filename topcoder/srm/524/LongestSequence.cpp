#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

struct E {
    int u, v;
    int next;
    E() {}
    E(int _u, int _v) : u(_u), v(_v) {}
};

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
};

struct SCCG {
    vector<int> color, order;
    Graph g, h;
    SCCG(int n) : g(n), h(n) {}
    void add_edge(int u, int v) {
        g.add(E(u, v));
        h.add(E(v, u));
    }
    void visit(const Graph& g, int at, int col) {
        if(color[at]>=0) return ;
        color[at] = col;
        for(int x=g.head[at]; x!=-1; x=g.es[x].next) {
            visit(g, g.es[x].v, col);
        }
        order.push_back(at);
    }
    void build() {
        const int n = g.n;
        order.clear();
        color = vector<int>(n, -1);
        rep(i, n) visit(g, i, i);
        color = vector<int>(n, -1);
        rep(i, n) visit(h, order[n-1-i], i);
    }
};

vector<int> c;

bool can(int n) {
    SCCG g(n+1);
    rep(k, n+1) rep(i, c.size()) if(k+abs(c[i])<=n) {
        const int kx = k+abs(c[i]);
        if(c[i]>0) g.add_edge(k, kx);
        else g.add_edge(kx, k);
    }
    g.build();
    vector<int> cnt(n+1, 0);
    rep(i, n+1) cnt[g.color[i]]++;
    rep(i, n+1) if(cnt[i]>1) return false;
    return true;
}

class LongestSequence {
    public:
    int maxLength(vector <int> C) {
        c = C;
        bool all = true;
        rep(i, c.size()) if(c[0]*c[i]<0) all = false;
        if(all) return -1;
        int l = 0, r = 5000;
        while(can(r)) r *= 2;
        while(r-l>1) {
            const int mid = (l+r)/2;
            if(can(mid)) l = mid;
            else r = mid;
        }
        return l;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
