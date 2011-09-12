#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct SCCG {
    static const int N=5000;
    int n, on, color[N], order[N];
    bool g[N][N], h[N][N];
    void init(int _n) { n=_n; memset(g, 0, sizeof(g)); memset(h, 0, sizeof(h)); }
    void add_edge(int _u, int _v) { g[_u][_v]=h[_v][_u]=true; }
    void scc_visit_1(int at, int col) {
        if(color[at]>=0) return ;
        color[at]=col;
        rep(i, n) if(g[at][i]) scc_visit_1(i, col);
        order[on++]=at;
    }
    void scc_visit_2(int at, int col) {
        if(color[at]>=0) return ;
        color[at]=col;
        rep(i, n) if(h[at][i]) scc_visit_2(i, col);
    }
    void scc() {
        on=0;
        memset(color, -1, sizeof(color));
        rep(i, n) scc_visit_1(i, i);
        memset(color, -1, sizeof(color));
        rep(i, n) scc_visit_2(order[n-1-i], i);
    }
} sccg;

int n, m, valid[5000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d", &m);
        sccg.init(n);
        rep(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            sccg.add_edge(u-1, v-1);
        }
        sccg.scc();
        memset(valid, -1, sizeof(valid));
        rep(i, n) if(valid[sccg.color[i]]) {
            rep(j, n) if(sccg.g[i][j] && sccg.color[i]!=sccg.color[j]) {
                valid[sccg.color[i]]=0;
                break;
            }
        }
        int c=0;
        rep(i, n) if(valid[sccg.color[i]]) {
            if(c++) putchar(' ');
            printf("%d", i+1);
        }
        putchar('\n');
    }
}

