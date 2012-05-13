#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int d, n, a[5000];

int main() {
    scanf("%d%d", &d, &n);
    rep (i, n) scanf("%d", a+i);
    int ans = 0;
    rep (i, n-1) ans += d-a[i];
    printf("%d\n", ans);
    return 0;
}
