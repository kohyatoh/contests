#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int tbl[500];

int main() {
    rep(i, 400) tbl[i+1] = tbl[i]+i+1;
    int T;
    scanf("%d", &T);
    rep(_t, T) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        rep(i, n+1) ans+=i*tbl[i+1];
        printf("%d %d %d\n", _t+1, n, ans);
    }
    return 0;
}
