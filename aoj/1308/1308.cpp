#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int M, N, D, S[32][32], a[768][768];

bool solve(int n) {
    int h = 0;
    rep(k, n) {
        int ix = -1;
        for(int i=h; i<n; i++) if(a[i][k]) { ix=i; break; }
        if(ix==-1) continue;
        if(h!=ix) rep(i, n+1) swap(a[h][i], a[ix][i]);
        rep(i, n) if(i!=h) if(a[i][k]) {
            for(int j=k; j<=n; j++) a[i][j] ^= a[h][j];
        }
        h++;
    }
    for(int i=h; i<n; i++) if(a[i][n]==1) return false;
    return true;
}

int main() {
    for(;;) {
        scanf("%d%d%d", &M, &N, &D);
        if(M==0 && N==0 && D==0) return 0;
        rep(i, N) rep(j, M) scanf("%d", S[i]+j);
        memset(a, 0, sizeof(a));
        const int n = N*M;
        rep(i, N) rep(j, M) {
            const int ix = i*M+j;
            a[ix][ix] = 1;
            a[ix][n] = S[i][j];
            rep(x, N) rep(y, M) if(abs(i-x)+abs(j-y)==D) a[ix][x*M+y] = 1;
        }
        printf("%d\n", (int)solve(n));
    }
}
