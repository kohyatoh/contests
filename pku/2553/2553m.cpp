#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct SCCG {
    static const int N=5000, M=N*N;
    int n, E, on, color[N], order[N];
    int ghead[N], gu[M], gv[M], gnext[M];
    int hhead[N], hu[M], hv[M], hnext[M];
    void init(int _n) {
        n=_n, E=0;
        memset(ghead, -1, sizeof(ghead));
        memset(hhead, -1, sizeof(hhead));
    }
    void add_edge(int _u, int _v) {
        gu[E]=_u; gv[E]=_v; gnext[E]=ghead[gu[E]]; ghead[gu[E]]=E;
        hu[E]=_v; hv[E]=_u; hnext[E]=hhead[hu[E]]; hhead[hu[E]]=E;
        E++;
    }
    void scc_visit_1(int at, int col) {
        if(color[at]>=0) return ;
        color[at]=col;
        for(int x=ghead[at]; x!=-1; x=gnext[x]) scc_visit_1(gv[x], col);
        order[on++]=at;
    }
    void scc_visit_2(int at, int col) {
        if(color[at]>=0) return ;
        color[at]=col;
        for(int x=hhead[at]; x!=-1; x=hnext[x]) scc_visit_2(hv[x], col);
    }
    void scc() {
        on=0;
        memset(color, -1, sizeof(color));
        rep(i, n) scc_visit_1(i, i);
        memset(color, -1, sizeof(color));
        rep(i, n) scc_visit_2(order[n-1-i], i);
    }
} g;

int n, m, valid[5000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d", &m);
        g.init(n);
        rep(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            g.add_edge(u-1, v-1);
        }
        g.scc();
        memset(valid, -1, sizeof(valid));
        rep(i, m) if(valid[g.color[g.gu[i]]]) {
            if(g.color[g.gu[i]]!=g.color[g.gv[i]]) {
                valid[g.color[g.gu[i]]]=0;
            }
        }
        int c=0;
        rep(i, n) if(valid[g.color[i]]) {
            if(c++) putchar(' ');
            printf("%d", i+1);
        }
        putchar('\n');
    }
}

