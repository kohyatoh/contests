#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, p[20000], f[20000];

int main() {
    scanf("%d", &T);
    rep(q, T) {
        rep(i, 20000) p[i]=f[i]=0;
        scanf("%d", &n);
        rep(i, n-1) {
            int a, b;
            scanf("%d%d", &a, &b);
            p[b]=a;
        }
        int x, y;
        scanf("%d%d", &x, &y);
        while(x>0) { f[x]=1; x=p[x]; }
        while(!f[y]) y=p[y];
        printf("%d\n", y);
    }
    return 0;
}

