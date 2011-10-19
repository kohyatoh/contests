#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct UnionDiff {
    vector<int> dat, col;
    UnionDiff(int _n) : dat(_n, -1), col(_n, 1) {}
    int size(int x) { return -dat[root(x)]; }
    int root(int x) {
        if(dat[x]<0) return x;
        const int r = root(dat[x]);
        col[x] *= col[dat[x]];
        return dat[x] = r;
    }
    int rel(int x, int y) {
        // no relation -> 0
        if(root(x)!=root(y)) return 0;
        // same -> 1, opposite -> -1
        return col[x]==col[y] ? 1 : -1;
    }
    bool opposite(int u, int v) {
        int x = root(u), y = root(v);
        const int c = -col[u]*col[v];
        if(x!=y) {
            if(dat[y]<dat[x]) std::swap(x, y);
            dat[x] += dat[y];
            dat[y] = x;
            col[y] = c;
        }
        return col[x] != col[y];
    }
};

char of[3][32] = {
    "In different gangs.",
    "Not sure yet.",
    "In the same gang.",
};

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        UnionDiff us(n);
        rep(_, m) {
            char op;
            int a, b;
            scanf(" %c%d%d", &op, &a, &b);
            a--, b--;
            if(op=='D') us.opposite(a, b);
            else puts(of[1+us.rel(a, b)]);
        }
    }
    return 0;
}
