#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[50000], u[3000];

int main() {
    m = 50000;
    rep(i, m) a[i]=i+2;
    rep(k, 3000) {
        if(m==0) break;
        u[k]=a[0];
        int z=0;
        for(int i=0; i<m; i++) if(i%u[k]) a[z++]=a[i];
        m = z;
    }
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        printf("%d\n", u[n-1]);
    }
}

