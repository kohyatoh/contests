#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[10][10], c[10], ans;

void rec(int d) {
    int mx=0;
    rep(i, n) if(mx<c[i]) mx=c[i];
    if(ans<=mx) return;
    if(d==n) {
        if(ans>mx) ans=mx;
        return;
    }
    rep(i, n) {
        rep(j, n) c[j]+=a[d][(j+i)%n];
        rec(d+1);
        rep(j, n) c[j]-=a[d][(j+i)%n];
    }
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==-1) return 0;
        rep(i, n) rep(j, n) scanf("%d", a[i]+j);
        ans = 1<<30;
        rep(i, n) c[i]=a[0][i];
        rec(1);
        printf("%d\n", ans);
    }
}

