#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

bool u[1000008];

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        int a = 0;
        for(int p=1; p*p*2<=n; p++) {
            for(int q=p+1; p*p+q*q<=n; q+=2) if(gcd(p, q)==1) {
                a++;
                const int x = q*q-p*p;
                const int y = 2*p*q;
                const int z = p*p+q*q;
                for(int k=1; k*z<=n; k++) u[k*x] = u[k*y] = u[k*z] = 1;
            }
        }
        int b = n;
        rep(i, n+1) if(u[i]) {
            b -= u[i];
            u[i] = 0;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
