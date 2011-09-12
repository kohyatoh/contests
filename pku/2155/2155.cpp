#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BIT {
    static const int N=1000;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
};

struct BIT2D {
    static const int N=1000;
    BIT x[N];
    void init() { rep(i, N) x[i].init(); }
    void add(int i, int j, int a) { for(; i<N; i|=i+1) x[i].add(j, a); }
    int sum(int i, int j) {
        int s=0;
        for(; i>=0; i=(i&(i+1))-1) s+=x[i].sum(j);
        return s;
    }
    int psum(int i, int j0, int j1) {
        int s=0;
        for(; i>=0; i=(i&(i+1))-1) s+=x[i].rsum(j0, j1);
        return s;
    }
    int rsum(int i0, int i1, int j0, int j1) {
        return i0==0 ? psum(i1, j0, j1) : psum(i1, j0, j1)-psum(i0-1, j0, j1);
    }
} bit2d;

int T, n, t;
char inst;

int main() {
    scanf("%d", &T);
    while(T--) {
        bit2d.init();
        scanf("%d%d", &n, &t);
        rep(i, t) {
            scanf(" %c", &inst);
            if(inst=='Q') {
                int x, y;
                scanf("%d%d", &x, &y);
                x--, y--;
                printf("%d\n", bit2d.rsum(x, n-1, y, n-1)%2);
            }
            else {
                int x0, y0, x1, y1;
                scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
                x0--, y0--, x1--, y1--;
                bit2d.add(x1, y1, 1);
                if(x0 && y0) bit2d.add(x0-1, y0-1, 1);
                if(x0) bit2d.add(x0-1, y1, 1);
                if(y0) bit2d.add(x1, y0-1, 1);
            }
        }
        if(T) puts("");
    }
    return 0;
}

