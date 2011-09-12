#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int y, n[22];

int main() {
    int k=1, t=1;
    double s=0;
    rep(i, 22) {
        t *= 2;
        while(s<=t) s+=log((double)++k)/log(2.0);
        n[i] = k-1;
    }
    for(;;) {
        scanf("%d", &y);
        if(y==0) return 0;
        printf("%d\n", n[(y-1950)/10]);
    }
    return 0;
}
