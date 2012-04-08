#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (1LL<<60)

struct MinCostFlow {
    static const int N = 5000;
    typedef long long cost_t;
    int E, head[N];
    vector<int> u, v, capa, rev, next, flow;
    vector<cost_t> cost;
    int s, t, prev[N];
    cost_t r, h[N], dist[N];
    void init() { E=0; memset(head, -1, sizeof(head)); }
    void add_edge(int _u, int _v, int ca, cost_t co) {
        u.push_back(_u); v.push_back(_v);
        capa.push_back(ca); cost.push_back(co);
        rev.push_back(-1); next.push_back(head[u[E]]);
        head[u[E]] = E; E++; flow.push_back(0);
    }
    void ready(int _s, int _t) {
        s=_s; t=_t;
        r=0;
        memset(h, 0, sizeof(h));
    }
    cost_t min_cost() { return r; }
    bool pour(int f) {
        while(f>0) {
            priority_queue<pair<cost_t, int> > q;
            std::fill_n(dist, N, INF);
            dist[s]=0;
            q.push(mp(0, s));
            while(!q.empty()) {
                pair<cost_t, int> z(q.top());
                q.pop();
                int cur=z.second;
                if(dist[cur]<-z.first) continue;
                for(int x=head[cur]; x!=-1; x=next[x]) if(capa[x]-flow[x]>0) {
                    if(dist[v[x]]>dist[cur]+cost[x]+h[cur]-h[v[x]]) {
                        dist[v[x]]=dist[cur]+cost[x]+h[cur]-h[v[x]];
                        prev[v[x]]=x;
                        q.push(mp(-dist[v[x]], v[x]));
                    }
                }
            }
            if(dist[t]==INF) return false;
            rep(i, N) h[i]+=dist[i];
            int d=f;
            for(int cur=t; cur!=s; cur=u[prev[cur]]) {
                d=min(d, capa[prev[cur]]-flow[prev[cur]]);
            }
            f -= d;
            r += d*h[t];
            for(int cur=t; cur!=s; cur=u[prev[cur]]) {
                if(cur!=s) {
                    const int e = prev[cur];
                    if(rev[e]==-1) {
                        rev[e] = E;
                        u.push_back(v[e]);
                        v.push_back(u[e]);
                        capa.push_back(0);
                        cost.push_back(-cost[e]);
                        rev.push_back(e);
                        next.push_back(head[u[E]]);
                        head[u[E]] = E;
                        E++;
                        flow.push_back(0);
                    }
                }
                flow[prev[cur]]+=d;
                flow[rev[prev[cur]]]-=d;
            }
        }
        return true;
    }
} mcf;

int N, K;
struct node { int x, t, p, i; } X[4000];
bool operator<(const node& l, const node& r) {
    if (l.x != r.x) return l.x < r.x;
    if (l.t != r.t) return l.t < r.t;
    if (l.p != r.p) return l.p < r.p;
    return l.i < r.i;
}

bool connect(int i, int j) {
    return X[i].x + X[i].t <= X[j].x;
}

int ans[4000];

int main() {
    scanf("%d%d", &N, &K);
    rep(i, N) {
        scanf("%d%d%d", &X[i].x, &X[i].t, &X[i].p);
        X[i].i = i;
    }
    sort(X, X+N);
    mcf.init();
    rep(i, N) mcf.add_edge(2+i*2, 2+i*2+1, 1, -X[i].p);
    rep(i, N) for(int j=i+1; j<N; j++) if(connect(i, j)) {
        mcf.add_edge(2+i*2+1, 2+j*2, 1, 0);
    }
    rep(i, N) mcf.add_edge(0, 2+i*2, 1, 0);
    rep(i, N) mcf.add_edge(2+i*2+1, 1, 1, 0);
    mcf.ready(0, 1);
    rep(i, N) {
        mcf.h[2+i*2+1] = mcf.h[2+i*2] - X[i].p;
        for(int j=i+1; j<N; j++) if(connect(i, j)) {
            mcf.h[2+j*2] = min(mcf.h[2+j*2], mcf.h[2+i*2+1]);
        }
        mcf.h[1] = min(mcf.h[1], mcf.h[2+i*2+1]);
    }
    mcf.pour(K);
//    cout << -mcf.min_cost() << endl;
    rep(i, N) if (mcf.flow[i]>0) ans[X[i].i] = 1;
    rep(i, N) printf("%d%c", ans[i], "\n "[i<N-1]);
//    rep (i, mcf.flow.size()) {
//        printf("%d -> %d: %d\n", mcf.u[i], mcf.v[i], mcf.flow[i]);
//    }
    return 0;
}
