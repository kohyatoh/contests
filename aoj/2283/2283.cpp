#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define pb push_back
#define mp make_pair

/** Edge-based graph with costs (directed or undirected) */
template<class C>
struct ECGraph {
    int n, m;
    vector<int> head, u, v, next;
    vector<C> c;
    ECGraph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(int _u, int _v, const C& _c) {
        u.pb(_u); v.pb(_v); c.pb(_c); next.pb(head[_u]); head[_u] = m++;
    }
};

/** Edge-based undirected graph with costs */
template<class C>
struct UECGraph : public ECGraph<C> {
    UECGraph(int n) : ECGraph<C>(n) {}
    void add(int u, int v, const C& c) {
        ECGraph<C>::add(u, v, c);
        ECGraph<C>::add(v, u, c);
    }
};

/** Dijkstra's shortest path algorithm */
template<class C>
C dijkstra(const ECGraph<C>& g, int s, int t) {
    typedef pair<C, int> T;
    priority_queue<T, vector<T>, greater<T> > q;
    set<int> vis;
    q.push(mp(0, s));
    while(!q.empty()) {
        T vv(q.top());
        q.pop();
        const C c(vv.first);
        const int at = vv.second;
        if(vis.count(at)) continue;
        vis.insert(at);
        if(at==t) return c;
        for(int x=g.head[at]; x!=-1; x=g.next[x]) {
            if(vis.count(g.v[x])==0) q.push(mp(c+g.c[x], g.v[x]));
        }
    }
    return -1;
}

/** Numbering the Key based on the order of appearance */
template<class Key>
class Numbering {
    map<Key, int> is;
public:
    int find(const Key& k) const {
        if(is.count(k)) return is.find(k)->second;
        return -1;
    }
    int ix(const Key& k) {
        int x = find(k);
        if(x==-1) {
            const int m = is.size();
            x = is[k] = m;
        }
        return x;
    }
};

int main() {
    for(;;) {
        int n, m;
        cin >> n >> m;
        if(n==0 && m==0) return 0;
        string S, P, G;
        cin >> S >> P >> G;
        UECGraph<int> g(n);
        Numbering<string> nb;
        rep(i, m) {
            string a, b;
            int d, t;
            cin >> a >> b >> d >> t;
            g.add(nb.ix(a), nb.ix(b), d/40+t);
        }
        printf("%d\n", dijkstra(g, nb.ix(S), nb.ix(P))
                + dijkstra(g, nb.ix(P), nb.ix(G)));
    }
}
