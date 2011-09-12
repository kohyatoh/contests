#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BiMatching {
    static const int n=1000;
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

int T, N;
int st[500], en[500], xs[500], ys[500], xe[500], ye[500];
int dist(int x1, int y1, int x2, int y2) { return abs(x2-x1)+abs(y2-y1); }

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        bm.init(N, N);
        rep(i, N) {
            int h, m;
            scanf("%d:%d%d%d%d%d", &h, &m, xs+i, ys+i, xe+i, ye+i);
            st[i] = h*60+m;
            en[i] = st[i]+dist(xs[i], ys[i], xe[i], ye[i]);
        }
        rep(i, N) rep(j, N) {
            if(en[i]+dist(xe[i], ye[i], xs[j], ys[j])<st[j]) {
                bm.add_edge(i, j);
            }
        }
        printf("%d\n", N-bm.match());
    }
    return 0;
}
