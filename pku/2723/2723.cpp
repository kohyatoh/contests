#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct SCCG {
    static const int N=2048, M=N*N;
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

int n, m, of[2048], x[2048], y[2048];

bool check(int k) {
    g.init(n*2);
    rep(i, k) {
        g.add_edge(x[i]^1, y[i]);
        g.add_edge(y[i]^1, x[i]);
    }
    g.scc();
    rep(i, n) if(g.color[2*i]==g.color[2*i+1]) return false;
    return true;
}

int main() {
    for(;;) {
        scanf(" %d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) {
            int a, b;
            scanf("%d%d", &a, &b);
            of[a] = i*2;
            of[b] = i*2+1;
        }
        rep(i, m) {
            int a, b;
            scanf("%d%d", &a, &b);
            x[i] = of[a];
            y[i] = of[b];
        }
        int l = 0, r = m+1;
        while(r-l>1) {
            const int mid = (l+r)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%d\n", l);
    }
}
