#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    for(;;) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n==0) return 0;
        double d=0;
        rep(i, n) d+=log(i+1);
        rep(i, m) d-=log(i+1);
        rep(i, n-m) d-=log(i+1);
        printf("%d things taken %d at a time is %u exactly.\n", n, m, (unsigned)(exp(d)+0.5));
    }
}
