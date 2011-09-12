#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

Int gcd(Int a, Int b) { return b==0 ? a : gcd(b, a%b); }

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, a[10];
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        Int ans = 1;
        rep(i, n) ans = ans*a[i]/gcd(ans, a[i]);
        if(ans > 1000000000) puts("More than a billion.");
        else printf("%d\n", (int)ans);
    }
    return 0;
}

