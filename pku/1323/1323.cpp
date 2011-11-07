#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[100], f[1024];

int main() {
    for(int _q=0;; _q++) {
        scanf(" %d%d", &m, &n);
        if(m==0) return 0;
        rep(i, n) scanf("%d", a+i);
        memset(f, 0, sizeof(f));
        rep(i, n) f[a[i]] = 1;
        int ans = 0, x = 0;
        for(int i=n*m; i>0; i--) {
            if(f[i]) {
                if(x>=0) ans++;
                else x++;
            }
            else {
                x--;
            }
        }
        printf("Case %d: %d\n", _q+1, ans);
    }
}
