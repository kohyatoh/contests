#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, sp, hs[100000], ps[100000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        sp=0;
        long long ans=0, t;
        rep(i, n+1) {
            int h, p=i;
            if(i<n) scanf("%d", &h);
            else h=-1;
            while(sp>0 && hs[sp-1]>=h) {
                t = (long long)hs[sp-1]*(i-ps[sp-1]);
                if(ans<t) ans=t;
                p = ps[sp-1];
                sp--;
            }
            hs[sp]=h;
            ps[sp]=p;
            sp++;
        }
        printf("%lld\n", ans);
    }
}
