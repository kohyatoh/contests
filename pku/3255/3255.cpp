#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, m, cnt[10000], sh[10000];
int E, u[400000], v[400000], cost[400000], next[400000], head[10000];

int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(sh, 1, sizeof(sh));
    rep(i, m) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        u[E]=a; v[E]=b; cost[E]=c; next[E]=head[u[E]]; head[u[E]]=E; E++;
        u[E]=b; v[E]=a; cost[E]=c; next[E]=head[u[E]]; head[u[E]]=E; E++;
    }
    priority_queue<pair<int, int> > q;
    q.push(mp(0, 0));
    while(!q.empty()) {
        pair<int, int> vx(q.top());
        q.pop();
        const int at = vx.second;
        if(cnt[at]==0) sh[at] = vx.first;
        else if(cnt[at]==1) {
            if(sh[at]==vx.first) continue; // dup shortest
            if(at==n-1) {
                printf("%d\n", -vx.first);
                break;
            }
        }
        else continue;
        cnt[at]++;
        for(int x=head[at]; x!=-1; x=next[x]) {
            q.push(mp(vx.first-cost[x], v[x]));
        }
    }
    return 0;
}
