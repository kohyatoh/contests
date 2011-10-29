#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[1024][1024];

bool solve(int n) {
    rep(k, n-1) {
        rep(i, n) rep(j, i) {
            if(a[k][i]+a[k+1][j]!=a[k][j]+a[k+1][i]) return false;
        }
    }
    return true;
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) rep(j, n) scanf(" %d", a[i]+j);
        printf("%shomogeneous\n", solve(n) ? "" : "not ");
    }
}
