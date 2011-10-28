#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[2000], b[2000];

int main() {
    for(int _q=0;; _q++) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d", &m);
        rep(i, m) scanf("%d%d", a+i, b+i);
        int Q;
        scanf("%d", &Q);
        printf("Genome %d\n", _q+1);
        while(Q--) {
            int x;
            scanf("%d", &x);
            rep(i, m) if(a[i]<=x && x<=b[i]) x = a[i]+b[i]-x;
            printf("%d\n", x);
        }
    }
}
