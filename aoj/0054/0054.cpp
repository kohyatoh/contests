#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, n;
    while (scanf("%d%d%d", &a, &b, &n) != EOF) {
        int ans = 0;
        a %= b;
        rep (_, n) {
            a *= 10;
            ans += a/b%10;
            a %= b;
        }
        printf("%d\n", ans);
    }
    return 0;
}
