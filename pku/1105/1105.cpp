#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[16];
char f[256], g[16];

int main() {
    for(int _q=0;; _q++) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) {
            int x;
            scanf(" x%d", &x);
            x--;
            a[x] = 1<<(n-1-i);
        }
        scanf(" %s", f);
        scanf("%d", &m);
        printf("S-Tree #%d:\n", _q+1);
        rep(_, m) {
            scanf(" %s", g);
            int cur = 0;
            rep(i, n) if(g[i]=='1') cur += a[i];
            putchar(f[cur]);
        }
        putchar('\n');
        putchar('\n');
    }
}
