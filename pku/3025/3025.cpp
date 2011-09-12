#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

inline double sq(double a) { return a*a; }
struct unionset {
    int ud[200];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int n, g[256][256];
double x[256], y[256], r[256];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==-1) return 0;
        rep(i, n) scanf("%lf%lf%lf", x+i, y+i, r+i);
        us.init();
        rep(i, n) rep(j, i) {
            const double d = sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
            if(d<abs(r[i]-r[j]) || d>r[i]+r[j]) continue;
            us.set(i, j);
        }
        int ans = 1;
        rep(i, n) ans = std::max(ans, us.size(i));
        printf("The largest component contains %d rings\n", ans);
    }
}
