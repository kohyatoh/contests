#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<30)
#define M (1000000)
int E, u[M], v[M], cost[M], next[M], head[1000];
int n, m, d[1000], memo[1000];

int rec(int cur) {
    if(cur==1) return 1;
    if(memo[cur]!=-1) return memo[cur];
    int ans=0;
    for(int x=head[cur]; x!=-1; x=next[x]) if(d[v[x]]<d[cur]) ans+=rec(v[x]);
    return memo[cur]=ans;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d", &m);
        memset(head, -1, sizeof(head));
        memset(memo, -1, sizeof(memo));
        rep(i, m) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            u[E]=a; v[E]=b; cost[E]=c; next[E]=head[u[E]]; head[u[E]]=E; E++;
            u[E]=b; v[E]=a; cost[E]=c; next[E]=head[u[E]]; head[u[E]]=E; E++;
        }
        priority_queue<pair<int, int> > q;
        rep(i, n) d[i]=INF;
        q.push(mp(0, 1));
        d[1]=0;
        while(!q.empty()) {
            pair<int, int> vx(q.top());
            q.pop();
            int cur=vx.second;
            if(d[cur]<-vx.first) continue;
            for(int x=head[cur]; x!=-1; x=next[x]) {
                if(d[v[x]]>-vx.first+cost[x]) {
                    q.push(mp(vx.first-cost[x], v[x]));
                    d[v[x]] = -vx.first+cost[x];
                }
            }
        }
        printf("%d\n", rec(0));
    }
}
