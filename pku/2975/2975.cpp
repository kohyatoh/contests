#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k[1000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", k+i);
        int x=0;
        rep(i, n) x^=k[i];
        int ans=0;
        rep(i, n) ans+=k[i]-(x^k[i])>0;
        printf("%d\n", ans);
    }
}
