#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<n; i++)

int T, n, m;
int f[2][100][100];
int vis[2][100];

int kount(int at, int d) {
    if(vis[d][at]) return 0;
    vis[d][at]=1;
    int c=1;
    rep(i, n) if(f[d][at][i]) c+=kount(i, d);
    return c;
}

int main() {
    scanf("%d", &T);
    rep(q, T) {
        memset(f, 0, sizeof(f));
        scanf("%d%d", &n, &m);
        rep(i, m) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--; b--;
            f[0][a][b]=1;
            f[1][b][a]=1;
        }
        int ans=0;
        rep(i, n) {
            memset(vis, 0, sizeof(vis));
            int h=kount(i, 0)-1, l=kount(i, 1)-1;
            if(h>n/2 || l>n/2) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
