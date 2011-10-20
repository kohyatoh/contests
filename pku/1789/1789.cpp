#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct unionset {
    int ud[2048];
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

int n, g[2048][2048];
char f[2048][8];

int solve() {
    int ans = 0;
    us.init();
    for(int k=1; k<=7; k++) {
        rep(i, n) rep(j, i) if(g[i][j]==k) {
            if(us.set(i, j)) ans += k;
            if(us.size(0)==n) return ans;
        }
    }
    return -1;
}

int main() {
    for(;;) {
        gets(f[0]);
        n = atoi(f[0]);
        if(n==0) return 0;
        rep(i, n) gets(f[i]);
        rep(i, n) rep(j, i) {
            int c = 0;
            rep(k, 7) c += f[i][k]!=f[j][k];
            g[i][j] = c;
        }
        printf("The highest possible quality is 1/%d.\n", solve());
    }
}
