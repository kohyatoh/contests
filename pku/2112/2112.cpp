#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BiMatching {
    static const int N=500;
    int h, w, g[N][N];
    int vis[N], cvis, mat[N];
    void init(int _h, int _w) { h=_h; w=_w; memset(g, 0, sizeof(g)); }
    void add_edge(int _u, int _v) { g[_u][_v]=1; }
    bool rec(int at) {
        if(at<0) return true;
        rep(i, w) if(g[at][i] && vis[i]!=cvis) {
            vis[i] = cvis;
            if(rec(mat[i])) {
            mat[i] = at;
                return true;
            }
        }
        return false;
    }
    int match() {
        memset(mat, -1, sizeof(mat));
        memset(vis, -1, sizeof(vis));
        int r=0;
        rep(i, h) {
            cvis = i;
            if(rec(i)) r++;
        }
        return r;
    }
} bm;

#define INF (1<<28)
int K, C, M, d[250][250];

bool can(int r) {
    bm.init(K*M, C);
    rep(i, K) rep(j, C) if(d[i][K+j]<=r) rep(t, M) bm.add_edge(i*M+t, j);
    return bm.match()==C;
}

int main() {
    scanf("%d%d%d", &K, &C, &M);
    int m=K+C;
    rep(i, m) rep(j, m) scanf("%d", d[i]+j);
    rep(i, m) rep(j, m) if(d[i][j]==0) d[i][j]=INF;
    rep(i, m) d[i][i]=0;
    rep(k, m) rep(i, m) rep(j, m) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    int l=0, r=300*300, mid;
    while(r-l>1) {
        mid = (l+r)/2;
        if(can(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n", r);
    return 0;
}
