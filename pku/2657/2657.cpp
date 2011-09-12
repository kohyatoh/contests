#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

int n, z, m, a, x[1000];

int main() {
    scanf("%d%d%d", &n, &z, &m);
    z--;
    rep(i, m) {
        scanf("%d", &a);
        x[a-1]=1;
    }
    for(int k=1; k<n; k++) if(z%gcd(n, k)==0) {
        for(int p=0; !x[p]; p=(p+k)%n) {
            if(p==z) {
                printf("%d\n", k);
                return 0;
            }
        }
    }
}
