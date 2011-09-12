#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

long long dec(int x, int b) {
    int c=0, d[8];
    rep(i, 8) { d[7-i]=x%10; x/=10; }
    rep(i, 8) if(d[i]>=b) return 0;
    rep(i, 8) c=c*b+d[i];
    return c;
}

int main() {
    int T, p, q, r;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &p, &q, &r);
        int ans=0;
        for(int b=2; b<=16; b++) {
            if(dec(p, b)*dec(q, b)==dec(r, b) && dec(r, b)>0) {
                ans = b;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
