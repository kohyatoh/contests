#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[10][10], b[10], c[10], ans;

void rec(int d) {
    if(d==n) {
        rep(i, n) c[i]=0;
        rep(i, n) rep(j, n) c[j]+=a[i][(j+b[i])%n];
        int mx=0;
        rep(i, n) if(mx<c[i]) mx=c[i];
        if(ans>mx) ans=mx;
        return;
    }
    rep(i, n) {
        b[d] = i;
        rec(d+1);
    }
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==-1) return 0;
        rep(i, n) rep(j, n) scanf("%d", a[i]+j);
        ans = 1<<30;
        rec(1);
        printf("%d\n", ans);
    }
}

