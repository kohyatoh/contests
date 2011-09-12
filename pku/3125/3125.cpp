#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, q[200], c[10];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        rep(i, n) scanf("%d", q+i);
        rep(i, 10) c[i] = 0;
        rep(i, n) c[q[i]]++;
        int ix = 9;
        while(c[ix]==0) ix--;
        int ans = 0;
        for(int i=0; ix>q[m] || i!=m; i=(i+1)%n) {
            if(ix==q[i]) {
                ans++;
                c[ix]--;
                while(c[ix]==0) ix--;
            }
        }
        printf("%d\n", ans+1);
    }
    return 0;
}
