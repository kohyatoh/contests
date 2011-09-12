#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[200];

int main() {
    rep(i, 200) a[i]=i*(i+1)/2;
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        int ans=0;
        rep(i, 200) {
            if(a[i]<=n) ans += i*i;
            else {
                ans += i*(n-a[i-1]);
                break;
            }
        }
        printf("%d %d\n", n, ans);
    }
}

