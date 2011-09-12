#include <stdio.h>
#include <string.h>
#include <algorithm>

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
} un;

int n, m, x, y;

int main() {
    for(int q=0;; q++) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        un.init();
        int ans=n;
        while(m--) {
            scanf("%d%d", &x, &y);
            x--, y--;
            if(!un.same(x, y)) un.set(x, y), ans--;
        }
        printf("Case %d: %d\n", q+1, ans);
    }
}
