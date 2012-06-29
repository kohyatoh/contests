#include <stdio.h>

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        int ans = 0;
        while (n) { ans += n/5; n/=5; }
        printf("%d\n", ans);
    }
}
