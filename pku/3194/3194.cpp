#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct UnionSet {
    int ud[128*128];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool set(int x, int y) {
        x = root(x); y = root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int n, f[128][128];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        memset(f, 0, sizeof(f));
        us.init();
        rep(i, n) rep(j, n) f[i+1][j+1] = n;
        rep(i, n-1) rep(j, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            f[x][y] = i+1;
        }
        rep(i, n) rep(j, n) rep(d, 4) {
            const int ni=i+dx[d], nj=j+dy[d];
            if(f[i+1][j+1]==f[ni+1][nj+1]) us.set(i*n+j, ni*n+nj);
        }
        bool yes = true;
        rep(i, n) rep(j, n) if(us.size(i*n+j)!=n) yes = false;
        puts(yes ? "good" : "wrong");
    }
}
