#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<28)

struct MinCostFlow {
    static const int N=2000, M=4000;
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

int w, b, k;

int main() {
    mcf.init();
    mcf.add_edge(2, 1, 15, 0);
    mcf.add_edge(3, 1, 15, 0);
    while(scanf("%d%d", &w, &b)!=EOF) {
        mcf.add_edge(0, k+4, 1, 0);
        mcf.add_edge(k+4, 2, 1, 100-w);
        mcf.add_edge(k+4, 3, 1, 100-b);
        k++;
    }
    mcf.ready(0, 1);
    mcf.pour(30);
    printf("%d\n", 3000-mcf.min_cost());
    return 0;
}

