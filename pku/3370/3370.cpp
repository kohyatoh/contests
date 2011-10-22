#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[100000], f[100000];

int main() {
    for(;;) {
        int c, n;
        scanf("%d%d", &c, &n);
        if(c==0 && n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        memset(f, -1, sizeof(f));
        f[0] = 0;
        int s = 0;
        rep(i, n) {
            s = (s+a[i])%c;
            if(f[s]!=-1) {
                for(int k=f[s]; k<=i; k++) printf("%d%c", k+1, k<i?' ':'\n');
                break;
            }
            f[s] = i+1;
        }
    }
}
