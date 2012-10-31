#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define pb push_back
typedef long long Int;

struct MinCostFlow {
    typedef Int cost_t;
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

int n;
int W[128][128], E[128][128];
char f[128][128];

int main() {
    scanf("%d", &n);
    rep (i, n) rep (j, n) scanf("%d", W[i]+j);
    rep (i, n) rep (j, n) scanf("%d", E[i]+j);
    rep (i, n) rep (j, n) scanf(" %c", f[i]+j);
    MinCostFlow mcf(2*n+2);
    Int base = 0, offset = 0;
    rep (i, n) rep (j, n) if (f[i][j] == 'o') {
        base += E[i][j];
        offset = max(offset, (Int)E[i][j]);
    }
    rep (i, n) rep (j, n) {
        if (f[i][j] == 'o') mcf.add(2+i, 2+n+j, 1, offset-E[i][j]);
        else mcf.add(2+i, 2+n+j, 1, offset+W[i][j]);
    }
    rep (i, n) mcf.add(0, 2+i, 1, 0);
    rep (i, n) mcf.add(2+n+i, 1, 1, 0);
    mcf.standby(0, 1);
    mcf.pour(n);
    Int ans = base + mcf.min_cost() - offset * n;
    printf("%d\n", (int)ans);
    int c = 0;
    rep (i, n) rep (j, n) {
        if (mcf.flow[2*(i*n+j)] && f[i][j] == '.') c++;
        if (!mcf.flow[2*(i*n+j)] && f[i][j] == 'o') c++;
    }
    printf("%d\n", c);
    rep (i, n) rep (j, n) {
        if (mcf.flow[2*(i*n+j)] && f[i][j] == '.') {
            printf("%d %d write\n", i+1, j+1);
        }
        if (!mcf.flow[2*(i*n+j)] && f[i][j] == 'o') {
            printf("%d %d erase\n", i+1, j+1);
        }
    }
    return 0;
}
