#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<30)

struct MinCostFlow {
    static const int N=300, M=80000;
    typedef int cost_t;
    int E, head[N], u[M], v[M], capa[M], rev[M], next[M];
    cost_t cost[M];
    int s, t, flow[M], prev[N];
    cost_t r, h[N], dist[N];
    void init() { E=0; memset(head, -1, sizeof(head)); }
    void add_edge(int _u, int _v, int ca, cost_t co) {
        u[E]=_u; v[E]=_v; capa[E]=ca; cost[E]=co; rev[E]=E+1, next[E]=head[u[E]]; head[u[E]]=E; E++;
        u[E]=_v; v[E]=_u; capa[E]=0; cost[E]=-co; rev[E]=E-1, next[E]=head[u[E]]; head[u[E]]=E; E++;
    }
    void ready(int _s, int _t) {
        s=_s; t=_t;
        r=0;
        memset(flow, 0, sizeof(flow));
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
                flow[prev[cur]]+=d;
                flow[rev[prev[cur]]]-=d;
            }
        }
        return true;
    }
} mcf;

int w, h, nm, xm[200], ym[200], nh, xh[200], yh[200], g[200][200];
char f[200][200];

int main() {
    for(;;) {
        scanf("%d%d", &h, &w);
        if(h==0 && w==0) return 0;
        nm = nh = 0;
        rep(j, h) rep(i, w) {
            scanf(" %c", f[i]+j);
            if(f[i][j]=='m') { xm[nm]=i; ym[nm]=j; nm++; }
            if(f[i][j]=='H') { xh[nh]=i; yh[nh]=j; nh++; }
        }
        rep(i, nm) rep(j, nh) g[i][j]=abs(xm[i]-xh[j])+abs(ym[i]-yh[j]);
        mcf.init();
        rep(i, nm) mcf.add_edge(0, 2+i, 1, 0);
        rep(i, nh) mcf.add_edge(2+nm+i, 1, 1, 0);
        rep(i, nm) rep(j, nh) mcf.add_edge(2+i, 2+nm+j, 1, g[i][j]);
        mcf.ready(0, 1);
        mcf.pour(nm);
        printf("%d\n", mcf.min_cost());
    }
}
