#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, a[32];
double dp[1<<20], zp[1<<20];

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i);
    for (int k = n-1; k >= 0; k--) {
        int b = (1<<k) - 1;
        while (b < (1<<n)) {
            const int all = (n-k)*(n-k-1)/2;
            rep (i, n) if (!(b&(1<<i))) rep (j, i) if (!(b&(1<<j))) {
                dp[b] += zp[b|(1<<i)|(1<<j)] / all;
            }
            if (b == 0) break;
            int x = b&-b, y = b+x;
            b = ((b&~y) / x >> 1) | y;
        }
        b = (1<<(k+1)) - 1;
        while (b < (1<<n)) {
            rep (i, n) if (b&(1<<i)) {
                zp[b] += (a[i] + dp[b-(1<<i)]) / (k+1);
            }
            if (b == 0) break;
            int x = b&-b, y = b+x;
            b = ((b&~y) / x >> 1) | y;
        }
    }
    printf("%.12f\n", dp[0]);
    return 0;
}
