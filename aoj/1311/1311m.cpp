#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int N, M, C, u[2000], v[2000];
int g[128][128], dp[2][128];

int main() {
    for(;;) {
        scanf("%d%d%d", &N, &M, &C);
        if(N==0) return 0;
        rep(i, N) rep(j, N) g[i][j] = i==j ? 0 : INF;
        rep(i, M) {
            int w;
            scanf("%d%d%d", u+i, v+i, &w);
            u[i]--, v[i]--;
            g[u[i]][v[i]] = w;
        }
        rep(k, N) rep(i, N) rep(j, N) g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        int *cur = dp[0], *nxt = dp[1];
        rep(i, N) cur[i] = g[0][i];
        rep(e, M+1) {
            if(cur[N-1]<=C) {
                printf("%d\n", e);
                break;
            }
            rep(i, N) nxt[i] = cur[i];
            rep(i, M) rep(j, N) nxt[j] = min(nxt[j], cur[u[i]]+g[v[i]][j]);
            swap(cur, nxt);
        }
    }
}

