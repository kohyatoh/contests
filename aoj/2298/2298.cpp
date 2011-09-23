#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, K, T, U, V, L, D[500];

int main() {
    scanf("%d%d%d%d%d%d", &N, &K, &T, &U, &V, &L);
    rep(i, N) scanf("%d", D+i);
    D[N++] = L;
    const int Z = T*V;
    int uL=0, vL=0, h=0, e=0, p=0;
    rep(i, N) {
        if(e>=D[i]) vL += D[i]-p;
        else {
            vL += e-p;
            uL += D[i]-e;
        }
        p = D[i];
        if(i==N-1) break;
        if(h<K) h++;
        else e = D[i]+Z;
        if(e<D[i]) e = D[i];
        while(h && e<D[i+1]) {
            e += Z;
            h--;
        }
    }
    printf("%.9f\n", (double)uL/U+(double)vL/V);
    return 0;
}

