#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<20)
int n, r, d, g[200][200], vis[200];
char a[80], b[80];

int main() {
    for(int ci=0;; ci++) {
        scanf("%d%d", &n, &r);
        if(n==0) return 0;
        memset(g, 0, sizeof(g));
        map<string, int> ids;
        int m=0;
        rep(i, r) {
            scanf(" %s%s%d", a, b, &d);
            int aix = ids.find(a)!=ids.end() ? ids[a] : (ids[a]=m++);
            int bix = ids.find(b)!=ids.end() ? ids[b] : (ids[b]=m++);
            g[aix][bix] = max(g[aix][bix], d);
            g[bix][aix] = max(g[bix][aix], d);
        }
        scanf(" %s%s", a, b);
        int six=ids[a], tix=ids[b];
        memset(vis, 0, sizeof(vis));
        priority_queue<pair<int, int> > q;
        q.push(mp(INF, six));
        while(!q.empty()) {
            pair<int, int> v=q.top();
            q.pop();
            int cur=v.second;
            if(vis[cur]) continue;
            vis[cur] = 1;
            if(cur==tix) {
                printf("Scenario #%d\n", ci+1);
                printf("%d tons\n", v.first);
                printf("\n");
                break;
            }
            rep(i, n) if(vis[i]==0 && g[cur][i]!=0) {
                q.push(mp(min(g[cur][i], v.first), i));
            }
        }
    }
}

