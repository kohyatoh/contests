#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int C[20][20];
int n, s, u[20], x[20];

bool rec(int at, int v) {
    if(at==n) return v==s;
    if(v>=s) return false;
    for(int i=1; i<=n; i++) if(u[i]==0) {
        const int rev = n-1-at;
        if(rev<at && x[rev]>i) continue;
        u[i] = 1;
        x[at] = i;
        if(rec(at+1, v+i*C[n-1][at])) return true;
        u[i] = 0;
    }
    return false;
}

int main() {
    C[0][0] = 1;
    rep(i, 15) rep(j, 15) C[i+1][j]+=C[i][j], C[i+1][j+1]+=C[i][j];
    scanf("%d%d", &n, &s);
    rec(0, 0);
    rep(i, n) printf("%d%c", x[i], i<n-1 ? ' ' : '\n');
    return 0;
}
