#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct UnionSet {
    int ud[128];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if (x!=y) {
            if (ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        us.init();
        rep (_, m) {
            int u, v;
            scanf(" %d%d", &u, &v);
            us.set(u, v);
        }
        int q;
        scanf("%d", &q);
        rep (_, q) {
            int u, v;
            scanf(" %d%d", &u, &v);
            puts(us.same(u, v) ? "YO" : "NO");
        }
    }
    return 0;
}
