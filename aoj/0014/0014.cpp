#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int d;
    while (scanf("%d", &d) != EOF) {
        int ans = 0;
        for (int i = 0; i < 600; i+=d) ans += i*i*d;
        printf("%d\n", ans);
    }
    return 0;
}
