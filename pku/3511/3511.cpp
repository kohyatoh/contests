#include <stdio.h>

int pt[1000000], is[1000000], xs[1000001], ys[1000001];

int main() {
    pt[0] = pt[1] = 1;
    for(int i=2; i<1000; i++) if(pt[i]==0) {
        for(int j=i*i; j<1000000; j+=i) pt[j] = i;
    }
    for(int i=1; i<1000; i++) for(int j=1; j<=i; j++) {
        const int a = i*i+j*j;
        if(a>=1000000) break;
        is[a] = 1;
    }
    for(int i=0; i<1000000; i++) xs[i+1] = xs[i]+(pt[i]==0);
    for(int i=0; i<1000000; i++) ys[i+1] = ys[i]+(pt[i]==0 && is[i]);
    for(;;) {
        int L, U;
        scanf("%d%d", &L, &U);
        if(L==-1 && U==-1) return 0;
        const int l = L>0 ? L : 0, u = U>0 ? U : 0;
        printf("%d %d %d %d\n", L, U, xs[u+1]-xs[l], ys[u+1]-ys[l]);
    }
}
