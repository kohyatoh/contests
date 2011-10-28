#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, k, a[40], b[40];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    rep(i, k) scanf("%d", a+i);
    rep(i, k) scanf("%d", b+i);
    int ans = 0;
    rep(i, k) if(a[i]>b[i]) ans += a[i]-b[i];
    printf("%d\n", ans);
    return 0;
}
