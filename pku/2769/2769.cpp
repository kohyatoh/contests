#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[500], is[2000000];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(is, 0, sizeof(is));
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        rep(i, n) rep(j, n) if(a[i]<a[j]) {
            const int d = a[j] - a[i];
            for(int p=1; p*p<=d; p++) if(d%p==0) {
                is[p] = is[d/p] = 1;
            }
        }
        int ans = 1;
        while(is[ans]) ans++;
        printf("%d\n", ans);
    }
}
