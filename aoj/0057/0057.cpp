#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int ans[12000];

int main() {
    ans[0] = 1;
    rep (i, 10000) ans[i+1] = ans[i]+i+1;
    int n;
    while (scanf("%d", &n) != EOF) printf("%d\n", ans[n]);
    return 0;
}
