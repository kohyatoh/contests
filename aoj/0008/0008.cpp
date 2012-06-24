#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cnt[64];

int main() {
    rep (a, 10) rep (b, 10) rep (c, 10) rep (d, 10) cnt[a+b+c+d]++;
    int n;
    while (scanf("%d", &n) != EOF) printf("%d\n", cnt[n]);
    return 0;
}
