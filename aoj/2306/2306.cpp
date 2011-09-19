#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, g[128][128], deg[128];

int rec(int ix, int rem, const vector<int>& u, const vector<int>& cs) {
    if(rem==0) {
        int ans = 0;
        rep(i, u.size()) if(u[i]==1) {
            int t = INT_MAX;
            rep(j, u.size()) if(i!=j && u[j]==1) t = min(t, g[cs[i]][cs[j]]);
            ans += t;
        }
        return ans;
    }
    int c = 0;
    for(int i=ix; i<(int)u.size(); i++) if(u[i]==0) c++;
    if(ix==(int)u.size() || c<rem) return 0;
    int ans = 0;
    if(u[ix]!=-1) {
        vector<int> w(u);
        w[ix] = 1;
        rep(i, w.size()) if(i!=ix && g[cs[ix]][cs[i]]==0) w[i] = -1;
        ans = max(ans, rec(ix+1, rem-1, w, cs));
    }
    ans = max(ans, rec(ix+1, rem, u, cs));
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, m) {
        int u, v, f;
        scanf("%d%d%d", &u, &v, &f);
        u--, v--;
        g[u][v] = g[v][u] = f;
        deg[u]++, deg[v]++;
    }
    int ans = 0;
    rep(i, n) rep(j, i) ans = max(ans, g[i][j]*2);
    rep(i, n) rep(j, i) if(g[i][j]) rep(k, j) if(g[k][i] && g[k][j]) {
        const int s = min(g[i][j], g[i][k])
                + min(g[j][i], g[j][k])
                + min(g[k][i], g[k][j]);
        ans = max(ans, s);
    }
    for(int k=4; k<15; k++) {
        vector<int> cs;
        rep(i, n) if(deg[i]>=k-1) cs.push_back(i);
        ans = max(ans, rec(0, k, vector<int>(cs.size(), 0), cs));
    }
    printf("%d\n", ans);
    return 0;
}
