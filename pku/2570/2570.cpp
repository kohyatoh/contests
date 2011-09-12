#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, u, v, g[200][200];
char s[100];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        memset(g, 0, sizeof(g));
        for(;;) {
            scanf("%d%d", &u, &v);
            if(u==0 && v==0) break;
            scanf("%s", s);
            for(char *p=s; *p; p++) g[u-1][v-1]|=1<<(*p-'a');
        }
        rep(k, n) rep(i, n) if(g[i][k]) rep(j, n) g[i][j]|=g[i][k]&g[k][j];
        for(;;) {
            scanf("%d%d", &u, &v);
            if(u==0 && v==0) break;
            if(g[u-1][v-1]==0) putchar('-');
            else rep(i, 26) if(g[u-1][v-1]&(1<<i)) putchar('a'+i);
            putchar('\n');
        }
        putchar('\n');
    }
}

