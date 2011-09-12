#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int T;
    scanf("%d", &T);
    rep(_t, T) {
        int a;
        scanf("%d", &a);
        int aq=0, ad=0, an=0, ap=a;
        for(int q=0; q*25<=a; q++) {
            int t = a-q*25;
            const int d = t/10;
            t %= 10;
            const int n = t/5;
            t %= 5;
            const int p = t;
            if(q+d+n+p<aq+ad+an+ap) aq=q, ad=d, an=n, ap=p;
        }
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
                _t+1, aq, ad, an, ap);
    }
    return 0;
}
