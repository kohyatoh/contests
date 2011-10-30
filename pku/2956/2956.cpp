#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int fact(int n) { return n==0 ? 1 : n*fact(n-1); }

int cnt[16], used[10];

int main() {
    cnt[0] = 9;
    rep(i, 10) cnt[i+1] = cnt[i]*(9-i);
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        int ix = 0;
        while(cnt[ix]<n) n -= cnt[ix++];
        rep(i, 10) used[i] = 0;
        for(int k=ix, r=10; k>=0; k--, r--) {
            const int f = fact(r-1)/fact(r-1-k);
            for(int i=k<ix?0:1; i<10; i++) if(!used[i]) {
                if(n<=f) {
                    used[i] = 1;
                    putchar('0' + i);
                    break;
                }
                n -= f;
            }
        }
        putchar('\n');
    }
}
