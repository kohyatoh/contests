#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<28)

int n, m, f, u, v, ll, x[500], y[500], d[500], g[500][20], l[500][20];

void dijkstra(int *a, priority_queue<pair<int, int> > &q) {
    while(!q.empty()) {
        pair<int, int> v(q.top());
        q.pop();
        int cur = v.second;
        if(a[cur]<-v.first) continue;
        a[cur] = -v.first;
        rep(i, d[cur]) if(a[g[cur][i]]>-v.first+l[cur][i]) {
            a[g[cur][i]] = -v.first+l[cur][i];
            q.push(mp(v.first-l[cur][i], g[cur][i]));
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);
    rep(i, n) x[i]=INF;
    priority_queue<pair<int, int> > q;
    rep(i, m) {
        scanf("%d", &f);
        q.push(mp(0, f-1));
    }
    while(scanf("%d%d%d", &u, &v, &ll)!=EOF) {
        u--, v--;
        g[u][d[u]]=v; l[u][d[u]]=ll; d[u]++;
        g[v][d[v]]=u; l[v][d[v]]=ll; d[v]++;
    }
    dijkstra(x, q);
    int mind=INF, ansi=-1;
    rep(k, n) {
        rep(i, n) y[i]=x[i];
        priority_queue<pair<int, int> > pq;
        pq.push(mp(0, k));
        dijkstra(y, pq);
        int ans=0;
        rep(i, n) ans=max(ans, y[i]);
        if(mind>ans) mind=ans, ansi=k;
    }
    printf("%d\n", ansi+1);
    return 0;
}
