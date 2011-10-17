#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct MaxFlow {
    static const int N=256;
    int n, flow[N][N], capa[N][N], prev[N];
    void init(int _n) {
        n = _n;
        memset(flow, 0, sizeof(flow));
        memset(capa, 0, sizeof(capa));
    }
    void add_edge(int u, int v, int ca) { capa[u][v] += ca; }
    int max(int s, int t, int F=1<<30) {
        int total = 0;
        while(total < F) {
            memset(prev, -1, sizeof(prev));
            queue<int> q;
            prev[s] = s;
            q.push(s);
            while(!q.empty() && prev[t]<0) {
                const int u = q.front();
                q.pop();
                rep(i, n) if(prev[i]<0 && flow[u][i]<capa[u][i]) {
                    prev[i] = u;
                    q.push(i);
                }
            }
            if(prev[t]<0) return total;
            int inc = F-total;
            for(int j=t; prev[j]!=j; j=prev[j]) {
                inc = min(inc, capa[prev[j]][j]-flow[prev[j]][j]);
            }
            for(int j=t; prev[j]!=j; j=prev[j]) {
                flow[prev[j]][j] += inc;
                flow[j][prev[j]] -= inc;
            }
            total += inc;
        }
        return total;
    }
} mf;

int n, m, deg[400];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        memset(deg, 0, sizeof(deg));
        mf.init(n+2);
        rep(i, m) {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            u--, v--;
            if(u==v) continue;
            deg[u]++, deg[v]--;
            if(d==0) mf.add_edge(v, u, 1);
        }
        bool ok = true;
        int a = 0;
        rep(i, n) {
            if(abs(deg[i])%2) ok = false;
            if(deg[i]>0) mf.add_edge(i, n+1, deg[i]/2), a+=deg[i]/2;
            if(deg[i]<0) mf.add_edge(n, i, -deg[i]/2);
        }
        puts(ok && mf.max(n, n+1)==a ? "possible" : "impossible");
    }
    return 0;
}
