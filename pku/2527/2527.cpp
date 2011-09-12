#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, a[20000];

int main() {
    for(;;) {
        scanf("%d%d", &n, &k);
        if(n==-1) return 0;
        rep(i, n+1) scanf("%d", a+i);
        for(int i=n-k; i>=0; i--) {
            a[i] -= a[i+k];
            a[i+k] = 0;
        }
        int m=n;
        while(m>0 && a[m]==0) m--;
        rep(i, m+1) printf("%d ", a[i]);
        printf("\n");
    }
}
