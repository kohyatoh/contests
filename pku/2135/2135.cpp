#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define pb push_back

struct MinCostFlow {
    typedef int cost_t;
    int n, m, s, t;
    vector<int> head, u, v, capa, rev, next, flow, prev;
    cost_t r;
    vector<cost_t> cost, h, dist;
    MinCostFlow(int _n)
        : n(_n), m(0), s(-1), head(_n, -1), prev(_n), h(_n), dist(_n)  {}
    void add(int _u, int _v, int ca, cost_t co) {
        u.pb(_u); v.pb(_v); capa.pb(ca); cost.pb(co);
        rev.pb(m+1); next.pb(head[u[m]]); head[u[m]]=m; m++;
        u.pb(_v); v.pb(_u); capa.pb(0); cost.pb(-co);
        rev.pb(m-1); next.pb(head[u[m]]); head[u[m]]=m; m++;
    }
    void standby(int _s, int _t) {
        s = _s; t = _t; r = 0;
        flow = vector<int>(m, 0);
        fill(h.begin(), h.end(), 0);
    }
    cost_t min_cost() { return r; }
    bool pour(int f) {
        const cost_t inf = 1<<28;
        assert(s>=0);
        while(f>0) {
            priority_queue<pair<cost_t, int> > q;
            std::fill(dist.begin(), dist.end(), inf);
            dist[s] = 0;
            q.push(mp(0, s));
            while(!q.empty()) {
                pair<cost_t, int> z(q.top());
                q.pop();
                int cur=z.second;
                if(dist[cur]<-z.first) continue;
                for(int x=head[cur]; x!=-1; x=next[x]) if(capa[x]-flow[x]>0) {
                    if(dist[v[x]]>dist[cur]+cost[x]+h[cur]-h[v[x]]) {
                        dist[v[x]] = dist[cur]+cost[x]+h[cur]-h[v[x]];
                        prev[v[x]] = x;
                        q.push(mp(-dist[v[x]], v[x]));
                    }
                }
            }
            if(dist[t]==inf) return false;
            rep(i, n) h[i] += dist[i];
            int d=f;
            for(int cur=t; cur!=s; cur=u[prev[cur]]) {
                d = min(d, capa[prev[cur]]-flow[prev[cur]]);
            }
            f -= d;
            r += d*h[t];
            for(int cur=t; cur!=s; cur=u[prev[cur]]) {
                flow[prev[cur]]+=d;
                flow[rev[prev[cur]]]-=d;
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    MinCostFlow mf(n);
    rep(i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--, v--;
        mf.add(u, v, 1, c);
        mf.add(v, u, 1, c);
    }
    mf.standby(0, n-1);
    mf.pour(2);
    printf("%d\n", mf.min_cost());
    return 0;
}
