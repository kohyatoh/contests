#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

vector<int> g[40000];
int vis[40000];

void visit(int at) {
    if(vis[at]) return;
    vis[at] = 1;
    rep(i, g[at].size()) visit(g[at][i]);
}

int main() {
    for(;;) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, 40000) g[i].clear();
        memset(vis, 0, sizeof(vis));
        rep(i, m) {
            int k;
            scanf("%d", &k);
            rep(j, k) {
                int a;
                scanf("%d", &a);
                g[a].push_back(n+i);
                g[n+i].push_back(a);
            }
        }
        visit(0);
        int ans = 0;
        rep(i, n) if(vis[i]) ans++;
        printf("%d\n", ans);
    }
}
