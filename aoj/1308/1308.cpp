#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bitset>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int M, N, D, S[32][32];
bitset<640> bits[640];

bool solve(int n) {
    int h = 0;
    rep(k, n) {
        int ix = -1;
        for(int i=h; i<n; i++) if(bits[i][k]) { ix=i; break; }
        if(ix==-1) continue;
        if(h!=ix) swap(bits[h], bits[ix]);
        rep(i, n) if(i!=h) if(bits[i][k]) bits[i] ^= bits[h];
        h++;
    }
    for(int i=h; i<n; i++) if(bits[i][n]) return false;
    return true;
}

int main() {
    for(;;) {
        scanf("%d%d%d", &M, &N, &D);
        if(M==0 && N==0 && D==0) return 0;
        rep(i, N) rep(j, M) scanf("%d", S[i]+j);
        const int n = N*M;
        rep(i, N) rep(j, M) {
            const int ix = i*M+j;
            bits[ix].reset();
            bits[ix].set(ix);
            if(S[i][j]) bits[ix].set(n);
            rep(x, N) rep(y, M) if(abs(i-x)+abs(j-y)==D) bits[ix].set(x*M+y);
        }
        printf("%d\n", (int)solve(n));
    }
}
