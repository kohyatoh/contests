#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[20000], p[20000];
vector<int> g[20000];

int calc(int at) {
    int s = 0;
    rep(i, g[at].size()) {
        const int j = g[at][i];
        s += calc(j);
        s += abs(a[j]-1);
        a[at] += a[j]-1;
    }
    return s;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, 20000) g[i].clear();
        memset(p, -1, sizeof(p));
        rep(_, n) {
            int ix, k, m;
            scanf("%d%d%d", &ix, &k, &m);
            ix--;
            a[ix] = k;
            rep(_, m) {
                int tx;
                scanf("%d", &tx);
                tx--;
                g[ix].push_back(tx);
                p[tx] = ix;
            }
        }
        rep(i, n) if(p[i]==-1) printf("%d\n", calc(i));
    }
}
