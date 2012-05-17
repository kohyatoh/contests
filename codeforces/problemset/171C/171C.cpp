#include <stdio.h>

int main() {
    int ans = 0, t, a;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &a);
        ans += a * i;
    }
    printf("%d\n", ans);
    return 0;
}
