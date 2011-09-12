#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BiMatching {
    static const int N=512;
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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    bm.init(n, n);
    rep(i, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        bm.add_edge(x-1, y-1);
    }
    printf("%d\n", bm.match());
    return 0;
}
