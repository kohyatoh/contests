#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int f[20];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        rep(i, n) f[i] = 0;
        int ix = 0;
        for(int k=1; k<=n; k++) {
            rep(i, k+1) {
                while(f[ix]) ix = (ix+1)%n;
                if(i==k) f[ix] = k;
                ix = (ix+1)%n;
            }
        }
        rep(i, n) printf("%d%c", f[i], i<n-1 ? ' ' : '\n');
    }
}
