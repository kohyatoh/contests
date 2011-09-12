#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int g[32][32];

int main() {
    int n, m, a, b;
    int ts = 0;
    while(scanf("%d", &m)!=EOF) {
        ts++;
        rep(i, 32) rep(j, 32) g[i][j] = 100*(i!=j);
        rep(i, 19) {
            if(i) scanf("%d", &m);
            rep(j, m) {
                scanf("%d", &a);
                a--;
                g[i][a] = g[a][i] = 1;
            }
        }
        rep(k, 20) rep(i, 20) rep(j, 20) g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
        scanf("%d", &n);
        printf("Test Set #%d\n", ts);
        rep(i, n) {
            scanf("%d%d", &a, &b);
            printf("%d to %d: %d\n", a, b, g[a-1][b-1]);
        }
        printf("\n");
    }
}
