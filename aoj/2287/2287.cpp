#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define EPS (1e-12)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct unionset {
    int ud[50000];
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

int W, H, Fx, Fy, F, P[16][16];
int L, T[16], X[16], Y[16], ans[16];
int e[16*16];
double v[16][16], f[16][16], s[16*16];

void fix_flow() {
    bool any = true;
    while(any) {
        rep(i, 16*16) s[i] = 0;
        rep(i, H) rep(j, W) s[us.root(i*W+j)] += f[i][j];
        rep(i, H) rep(j, W) f[i][j] = s[us.root(i*W+j)]/us.size(i*W+j);
        any = false;
        rep(i, H) rep(j, W) if(f[i][j] && v[i][j]==30*30*30) {
            rep(d, 4) {
                const int x = i+dx[d], y = j+dy[d];
                if(x<0 || x>=H || y<0 || y>=W || P[i][j]<=P[x][y]) continue;
                f[x][y] += f[i][j]*us.size(i*W+j)/e[us.root(i*W+j)];
            }
            any = true;
            f[i][j] = 0;
        }
    }
}

void simulate() {
    us.init();
    rep(i, H) rep(j, W) rep(d, 4) {
        const int x = i+dx[d], y = j+dy[d];
        if(x<0 || x>=H || y<0 || y>=W) continue;
        if(P[i][j]==P[x][y]) us.set(i*W+j, x*W+y);
    }
    rep(i, 16*16) e[i] = 0;
    rep(i, H) rep(j, W) rep(d, 4) {
        const int x = i+dx[d], y = j+dy[d];
        if(x>=0 && x<H && y>=0 && y<W && P[i][j]<=P[x][y]) continue;
        e[us.root(i*W+j)]++;
    }
    int mt = 1;
    rep(i, L) mt = max(mt, T[i]+1);
    rep(i, H) rep(j, W) v[i][j] = 0;
    rep(i, H) rep(j, W) f[i][j] = 0;
    f[Fy][Fx] = F;
    double ct = 0;
    while(ct<mt) {
        fix_flow();
        double dt = 10000;
        rep(i, H) rep(j, W) if(f[i][j] && v[i][j]<30*30*30) {
            dt = min(dt, (30*30*30-v[i][j])/f[i][j]);
        }
        rep(i, L) if(ct-EPS<T[i] && T[i]<ct+dt+EPS) {
            const int x = Y[i], y = X[i];
            ans[i] = (v[x][y]+f[x][y]*(T[i]-ct))/(30*30);
        }
        rep(i, H) rep(j, W) {
            v[i][j] += dt*f[i][j];
            if(v[i][j]>30*30*30-EPS) v[i][j] = 30*30*30;
        }
        ct += dt;
    }
}

int main() {
    for(;;) {
        scanf("%d%d", &W, &H);
        if(W==0 && H==0) return 0;
        scanf("%d%d%d", &Fx, &Fy, &F);
        rep(i, H) rep(j, W) scanf("%d", P[i]+j);
        scanf("%d", &L);
        rep(i, L) scanf("%d%d%d", T+i, X+i, Y+i);
        simulate();
        rep(i, L) printf("%d\n", ans[i]);
    }
}
