#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1<<28)
#define M (10000)
int E, u[M], v[M], cost[M], len[M], rnext[M], rhead[M];
int n, m, a, b, vc[1200], mc[1200], ml[1200], neg[1200], vis[1200];

void add_edge(int _u, int _v, int co, int L) {
    if(vc[_u]>=co) {
        u[E]=_u; v[E]=_v; cost[E]=co; len[E]=L; E++;
        vc[_u]=co;
    }
}

void rec(int cur) {
    if(vis[cur]) return ;
    vis[cur] = 1;
    for(int x=rhead[cur]; x!=-1; x=rnext[x]) rec(u[x]);
}

int main() {
    while(scanf("%d%d%d%d", &n, &m, &a, &b)!=EOF) {
        E = 0;
        memset(rhead, -1, sizeof(rhead));
        memset(neg, 0, sizeof(neg));
        memset(vis, 0, sizeof(vis));
        rep(i, n) vc[i]=mc[i]=ml[i]=INF;
        rep(i, m) {
            int s, t, f1, f2, L;
            scanf(" (%d,%d,%d[%d]%d)", &s, &t, &f1, &L, &f2);
            add_edge(s, t, f1, L);
            add_edge(t, s, f2, L);
        }
        int E2=0;
        rep(i, E) if(cost[i]<=vc[u[i]]) {
            u[E2]=u[i]; v[E2]=v[i]; cost[E2]=cost[i]; len[E2]=len[i]; E2++;
        }
        E = E2;
        rep(i, E) {
            rnext[i]=rhead[v[i]]; rhead[v[i]]=i;
        }
        mc[a]=ml[a]=0;
        rep(q, n+10) {
            bool update=false;
            rep(i, E) if(mc[u[i]]!=INF) {
                if(mc[v[i]]>mc[u[i]]+cost[i]) {
                    mc[v[i]] = mc[u[i]]+cost[i];
                    ml[v[i]] = ml[u[i]]+len[i];
                    update = true;
                    if(q>=n) neg[v[i]]=1;
                }
                else if(mc[v[i]]==mc[u[i]]+cost[i]) {
                    if(ml[v[i]]>ml[u[i]]+len[i]) {
                        ml[v[i]] = ml[u[i]]+len[i];
                        update = true;
                    }
                }
            }
            if(!update) break;
        }
        rec(b);
        bool unbound=false;
        rep(i, n) if(neg[i] && vis[i]) unbound=true;
        if(mc[b]==INF) puts("VOID");
        else if(unbound) puts("UNBOUND");
        else printf("%d %d\n", mc[b], ml[b]);
    }
    return 0;
}
