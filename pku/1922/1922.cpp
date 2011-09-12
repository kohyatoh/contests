#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int n;
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        int ans=-1;
        int v, t;
        rep(i, n) {
            scanf("%d%d", &v, &t);
            if(t<0) continue;
            int r=ceil(60*60*4.5/v)+t;
            if(ans==-1 || ans>r) ans=r;
        }
        printf("%d\n", ans);
    }
}

