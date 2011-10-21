#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int N, M, T, g[512][512];

int main() {
    scanf("%d%d%d", &N, &M, &T);
    rep(i, N) rep(j, N) g[i][j] = INT_MAX;
    rep(i, N) g[i][i] = 0;
    rep(i, M) {
        int u, v, h;
        scanf("%d%d%d", &u, &v, &h);
        u--, v--;
        cmin(g[u][v], h);
    }
    rep(k, N) rep(i, N) rep(j, N) cmin(g[i][j], max(g[i][k], g[k][j]));
    rep(i, T) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        printf("%d\n", g[u][v]<INT_MAX ? g[u][v] : -1);
    }
    return 0;
}
