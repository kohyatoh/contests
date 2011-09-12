#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, k;
double v[10000], sm, sn, psm, psn;

int main() {
    scanf("%d%d%d", &m, &n, &k);
    rep(i, k) {
        scanf("%lf", v+i);
        sm += v[i];
        if(i>=m) sm-=v[i-m];
        sn += v[i];
        if(i>=n) sn-=v[i-n];
        if(i+1<n) continue;
        if(sm/m>sn/n) {
            if(i+1==n || psm/m<psn/n) printf("BUY ON DAY %d\n", i+1);
        }
        else {
            if(i+1==n || psm/m>psn/n) printf("SELL ON DAY %d\n", i+1);
        }
        psm = sm;
        psn = sn;
    }
    return 0;
}
