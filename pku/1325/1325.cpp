#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BiMatching {
    static const int n=100;
    int h, w, g[n][n];
    int vis[n], cvis, mat[n];
    void init(int _h, int _w) { h=_h; w=_w; memset(g, 0, sizeof(g)); }
    void add_edge(int s, int t) { g[s][t]=1; }
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

int n, m, k;

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d%d", &m, &k);
        bm.init(n, m);
        rep(i, k) {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
            if(x==0 || y==0) continue;
            bm.add_edge(x, y);
        }
        printf("%d\n", bm.match());
    }
}
