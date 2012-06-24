#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int k = a+b, ans = 0;
        do {
            ans++;
            k /= 10;
        } while(k);
        printf("%d\n", ans);
    }
    return 0;
}
