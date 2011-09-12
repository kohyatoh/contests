#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, t, p[10000];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0) return 0;
        memset(p, 0, sizeof(p));
        rep(i, n) rep(j, m) { scanf("%d", &t); p[t-1]++; }
        int mx=0, sc=0, c=0;
        rep(i, 10000) if(mx<p[i]) mx=p[i];
        rep(i, 10000) if(p[i]<mx && sc<p[i]) sc=p[i];
        rep(i, 10000) if(p[i]==sc) {
            if(c++) putchar(' ');
            printf("%d", i+1);
        }
        putchar('\n');
    }
}
