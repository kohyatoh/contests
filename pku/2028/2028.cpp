#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, q, f[100];

int main() {
    for(;;) {
        scanf("%d%d", &n, &q);
        if(n==0 && q==0) return 0;
        rep(i, 100) f[i]=0;
        rep(k, n) {
            int m, d;
            scanf("%d", &m);
            rep(i, m) {
                scanf("%d", &d);
                f[d]++;
            }
        }
        int maxi=0, maxc=0;
        rep(i, 100) if(f[i]>=q) {
            if(maxc<f[i]) {
                maxc=f[i];
                maxi=i;
            }
        }
        printf("%d\n", maxi);
    }
}
