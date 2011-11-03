#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, G, m[30], a[30][8], el[8], cnt[8];

int main() {
    for(;;) {
        scanf("%d%d", &G, &N);
        if(G==0 && N==0) return 0;
        rep(i, G) {
            scanf("%d", m+i);
            rep(j, N) scanf("%d", a[i]+j);
        }
        rep(i, G) rep(j, N) a[i][j]--;
        rep(i, N) el[i] = 0;
        rep(_, N-1) {
            rep(i, N) cnt[i] = 0;
            rep(i, G) {
                int ix = 0;
                while(el[a[i][ix]]) ix++;
                cnt[a[i][ix]] += m[i];
            }
            int ix = -1;
            rep(i, N) if(!el[i]) {
                if(ix==-1 || cnt[i]<=cnt[ix]) ix = i;
            }
            el[ix] = 1;
        }
        rep(i, N) if(el[i]==0) printf("%d\n", i+1);
    }
}
