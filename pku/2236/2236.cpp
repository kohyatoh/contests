#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct unionset {
    int ud[2000];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x), y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} un;

inline int sq(int a) { return a*a; }

int n, d, x[2000], y[2000], u[2000];

int main() {
    scanf("%d%d", &n, &d);
    rep(i, n) scanf("%d%d", x+i, y+i);
    un.init();
    char op;
    while(scanf(" %c", &op)!=EOF) {
        if(op=='O') {
            int k;
            scanf("%d", &k);
            k--;
            rep(i, n) if(u[i] && sq(x[i]-x[k])+sq(y[i]-y[k])<=sq(d)) un.set(k, i);
            u[k] = 1;
        }
        else if(op=='S') {
            int p, q;
            scanf("%d%d", &p, &q);
            p--, q--;
            puts(un.same(p, q) ? "SUCCESS" : "FAIL");
        }
    }
    return 0;
}

