#include <stdio.h>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int T, n, d[600][600];
bool vis[600];

int main() {
    scanf("%d", &T);
    rep(qq, T) {
        scanf("%d", &n);
        rep(i, n) rep(j, n) scanf("%d", d[i]+j);
        rep(i, n) vis[i]=false;
        int ans=0, k=0;
        priority_queue<pair<int, int> > q;
        q.push(mp(0, 0));
        while(k<n) {
            pair<int, int> v=q.top(); q.pop();
            if(vis[v.second]) continue;
            vis[v.second] = true;
            ans = max(ans, -v.first);
            k++;
            rep(i, n) if(!vis[i]) q.push(mp(-d[v.second][i], i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
