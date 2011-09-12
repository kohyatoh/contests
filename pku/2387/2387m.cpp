#include <stdio.h>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int d[1000];
int N, T;
int m[1000], to[1000][1000], cost[1000][1000];
#define INF (1<<28)

int main() {
    scanf("%d%d", &T, &N);
    rep(i, T) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        to[a-1][m[a-1]]=b-1; cost[a-1][m[a-1]]=c; m[a-1]++;
        to[b-1][m[b-1]]=a-1; cost[b-1][m[b-1]]=c; m[b-1]++;
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
        rep(i, m[cur]) if(d[to[cur][i]]==INF) {
            q.push(mp(v.first-cost[cur][i], to[cur][i]));
        }
    }
    printf("%d\n", d[N-1]);
    return 0;
}
