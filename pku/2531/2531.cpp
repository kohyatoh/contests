#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, c[20][20];

int main() {
    scanf("%d", &n);
    rep(i, n) rep(j, n) scanf("%d", c[i]+j);
    int ans=0;
    int nn=1<<n;
    for(int k=1; k<n/2+1; k++) {
        int b=(1<<k)-1;
        while(b<nn) {
            int s=0;
            rep(i, n) if(b&(1<<i)) rep(j, n) if(!(b&(1<<j))) s+=c[i][j];
            if(ans<s) ans=s;
            int x=b&-b; int y=b+x;
            b=((b&~y)/x>>1)|y;
        }
    }
    printf("%d\n", ans);
    return 0;
}
