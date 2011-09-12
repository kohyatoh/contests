#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, d, a[100];

int main() {
    for(;;) {
        scanf("%d%d", &n, &d);
        if(n==0 && d==0) return 0;
        memset(a, 0, sizeof(a));
        a[0] = 1;
        rep(_, d) {
            int carry = 0;
            rep(i, 99) {
                const int x = a[i]*n+carry;
                a[i] = x%10;
                carry = x/10;
            }
        }
        int ix = 99;
        while(ix>0 && a[ix]==0) ix--;
        while(ix>=0) printf("%d", a[ix--]);
        puts("");
    }
}
