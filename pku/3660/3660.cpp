#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, M, g[128][128];

int main() {
    scanf("%d%d", &N, &M);
    rep(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a][b] |= 1;
        g[b][a] |= 2;
    }
    rep(k, N) rep(i, N) rep(j, N) g[i][j] |= g[i][k]&g[k][j];
    int ans = 0;
    rep(i, N) {
        bool ok = true;
        rep(j, N) if(i!=j && g[i][j]==0) { ok = false; break; }
        if(ok) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
