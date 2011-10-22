#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, P, K;
vector<int> vs[1024], ws[1024];
int dp[1024], Qi, Qn, Q[1024];
int m, cd;

void dfs(int x) {
    Q[Qn++] = x;
    dp[x] = cd;
    rep(i, vs[x].size()) if(dp[vs[x][i]]==-1 && ws[x][i]<=m) dfs(vs[x][i]);
}

bool ok(int _m) {
    m = _m;
    cd = 0;
    memset(dp, -1, sizeof(dp));
    Qi = Qn = 0;
    dfs(0);
    while(Qi<Qn) {
        const int x = Q[Qi++];
        if(x==N-1) return true;
        if(dp[x]==K) continue;
        cd = dp[x]+1;
        rep(i, vs[x].size()) if(dp[vs[x][i]]==-1 && ws[x][i]>m) dfs(vs[x][i]);
    }
    return false;
}

int main() {
    scanf("%d%d%d", &N, &P, &K);
    int L = 0;
    rep(i, P) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        L = max(L, w);
        vs[u].push_back(v); ws[u].push_back(w);
        vs[v].push_back(u); ws[v].push_back(w);
    }
    int l = -1, r = L+1;
    while(r-l>1) {
        const int mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n", r<=L ? r : -1);
    return 0;
}
