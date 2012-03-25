#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, x, y, p[200000], q[200000], as[200000];

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    rep (i, n) scanf("%d", p+i);
    rep (i, m) scanf("%d", q+i);
    int ans = 0, ix = 0;
    rep (i, m) {
        while (ix < n && p[ix]+y < q[i]) ix++;
        if (ix == n) break;
        if (q[i] >= p[ix]-x) {
            ans++;
            as[i] = ix+1;
            ix++;
        }
    }
    printf("%d\n", ans);
    rep (i, m) if (as[i]) printf("%d %d\n", as[i], i+1);
    return 0;
}
