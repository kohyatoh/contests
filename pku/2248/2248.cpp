#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[100], an, ans[100];

void rec(int k) {
    if(k>10 || k>=an) return;
    if(a[k-1]==n) {
        an = k;
        rep(i, an) ans[i]=a[i];
    }
    rep(i, k) {
        if(a[k-1]+a[i]<=n) {
            a[k] = a[k-1]+a[i];
            rec(k+1);
        }
    }
}

int main() {
    a[0] = 1;
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        an = n;
        rep(i, n) ans[i]=i+1;
        rec(1);
        rep(i, an) printf("%d%c", ans[i], i==an-1 ? '\n' : ' ');
    }
}

