#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        const int g = gcd(a, b);
        printf("%d %d\n", g, a/g*b);
    }
    return 0;
}
