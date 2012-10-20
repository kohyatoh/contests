#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, a, b;
    scanf("%d", &n);
    int s = 0;
    rep (_, n) {
        scanf("%d%d", &a, &b);
        s += a*b;
    }
    printf("%d\n", (int)(s*1.05));
    return 0;
}
