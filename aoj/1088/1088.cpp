#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i  < (int)(n); i++)
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

int n, m[128], x[128][32], y[128][32], c[128][32], g;
int base[128];
vector<int> t[128];

int of(int k, int ti) {
    return base[k] + (lower_bound(t[k].begin(), t[k].end(), ti)-t[k].begin());
}

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (k, n-1) {
            scanf("%d", m+k);
            rep (i, m[k]) scanf("%d%d%d", x[k]+i, y[k]+i, c[k]+i);
        }
        scanf("%d", &g);
        rep (i, 128) t[i].clear();
        t[0].push_back(0);
        rep (k, n-1) rep (i, m[k]) t[k+1].push_back(y[k][i]);
        rep (k, n) {
            sort(t[k].begin(), t[k].end());
            t[k].erase(unique(t[k].begin(), t[k].end()), t[k].end());
            base[k+1] = base[k] + t[k].size();
        }
        MinCostFlow mcf(base[n]*2);
        rep (k, n) rep (i, t[k].size()) {
            mcf.add((base[k]+i)*2, (base[k]+i)*2+1, 1, 0);
            if (i+1 < (int)t[k].size()) {
                mcf.add((base[k]+i)*2+1, (base[k]+i+1)*2+1, 1<<28, 0);
            }
        }
        rep (k, n-1) rep (i, m[k]) {
            int ix = -1;
            while (ix < (int)t[k].size()-1 && t[k][ix+1] <= x[k][i]) ix++;
            if (ix == -1) continue;
            mcf.add((base[k]+ix)*2+1, of(k+1, y[k][i])*2, 1, c[k][i]);
        }
        mcf.standby(1, base[n]*2-1);
        int ansk = 0, ans = 0;
        while (mcf.pour(1)) {
            ansk++;
            ans = mcf.min_cost();
            if (ansk == g) break;
        }
        printf("%d %d\n", ansk, ans);
    }
}
