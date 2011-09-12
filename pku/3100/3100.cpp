#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ipow(int a, int x) {
    int r = 1;
    while(x--) r*=a;
    return r;
}

int main() {
    for(;;) {
        int b, n;
        scanf("%d%d", &b, &n);
        if(b==0 && n==0) return 0;
        int ans=-1, df=1<<20;
        for(int a=pow(b, 1.0/n)-2, i=0; i<5; a++, i++) if(a>0) {
            const int d = abs(ipow(a, n)-b);
            if(df>d) ans=a, df=d;
        }
        printf("%d\n", ans);
    }
}
