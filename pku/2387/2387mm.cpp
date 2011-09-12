#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<28)
int d[1000];
int N, T;
int E, from[5000], to[5000], cost[5000], head[5000], next[5000];
void init() { E=0; memset(head, -1, sizeof(head)); }
void add_edge(int s, int t, int c) {
    from[E]=s; to[E]=t; cost[E]=c; next[E]=head[s]; head[s]=E; E++;
}

int main() {
    scanf("%d%d", &T, &N);
    init();
    rep(i, T) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edge(a-1, b-1, c);
        add_edge(b-1, a-1, c);
    }
    rep(i, N) d[i]=INF;
    priority_queue<pair<int, int> > q;
    q.push(mp(0, 0));
    while(!q.empty()) {
        pair<int, int> v=q.top();
        q.pop();
        int cur=v.second;
        if(d[cur]!=INF) continue;
        d[cur] = -v.first;
        for(int x=head[cur]; x!=-1; x=next[x]) if(d[to[x]]==INF) {
            q.push(mp(v.first-cost[x], to[x]));
        }
    }
    printf("%d\n", d[N-1]);
    return 0;
}
