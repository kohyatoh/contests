#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int k, n, m, a[100], vis[100][1000];
vector<int> g[1000];

void visit(int cow, int at) {
    if(vis[cow][at]) return ;
    vis[cow][at] = 1;
    rep(i, g[at].size()) visit(cow, g[at][i]);
}

int main() {
    scanf("%d%d%d", &k, &n, &m);
    rep(i, k) scanf("%d", a+i);
    rep(i, k) a[i]--;
    rep(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
    }
    rep(i, k) visit(i, a[i]);
    int ans = 0;
    rep(i, n) {
        bool f = true;
        rep(j, k) if(vis[j][i]==0) f=false;
        if(f) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
