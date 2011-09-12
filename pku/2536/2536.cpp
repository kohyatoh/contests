#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BiMatching {
    static const int N=100;
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

int n, m;
double s, v, xg[100], yg[100], xh[100], yh[100];

int main() {
    while(scanf("%d%d%lf%lf", &n, &m, &s, &v)!=EOF) {
        rep(i, n) scanf("%lf%lf", xg+i, yg+i);
        rep(i, m) scanf("%lf%lf", xh+i, yh+i);
        bm.init(n, m);
        rep(i, n) rep(j, m) {
            if(hypot(xg[i]-xh[j], yg[i]-yh[j])<=s*v) bm.add_edge(i, j);
        }
        printf("%d\n", n-bm.match());
    }
    return 0;
}

