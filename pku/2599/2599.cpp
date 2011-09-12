#include <stdio.h>
#include <set>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, u, v, d[1000], g[1000][20];

bool win(int at, int pre) {
    rep(i, d[at]) if(g[at][i]!=pre && !win(g[at][i], at)) return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    while(scanf("%d%d", &u, &v)!=EOF) {
        u--, v--;
        g[u][d[u]++] = v;
        g[v][d[v]++] = u;
    }
    rep(i, d[k-1]) if(!win(g[k-1][i], k-1)) {
        printf("First player wins flying to airport %d\n", g[k-1][i]+1);
        return 0;
    }
    printf("First player loses\n");
    return 0;
}
