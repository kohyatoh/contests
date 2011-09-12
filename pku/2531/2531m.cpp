#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, c[20][20], u[20];
int ans;

void rec(int d, int f, int r) {
    if(ans>=f+r) return ;
    if(d==n) {
        if(ans<f) ans = f;
        return ;
    }
    int p=0, q=0, t=0;
    rep(i, d) if(u[i]) p+=c[i][d], t++; else q+=c[i][d];
    u[d]=1;
    if(t<n/2) rec(d+1, f+q, r-p-q);
    u[d]=0;
    rec(d+1, f+p, r-p-q);
}

int main() {
    scanf("%d", &n);
    rep(i, n) rep(j, n) scanf("%d", c[i]+j);
    int s=0;
    rep(i, n) rep(j, i) s+=c[i][j];
    rec(0, 0, s);
    printf("%d\n", ans);
    return 0;
}
