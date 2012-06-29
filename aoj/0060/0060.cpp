#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int c1, c2, c3;
    while (scanf("%d%d%d", &c1, &c2, &c3) != EOF) {
        int a = 0, b = 0;
        rep (i, 10) if (i+1 != c1 && i+1 != c2 && i+1 != c3) {
            if (c1+c2+i+1 <= 20) a++; else b++;
        }
        puts(a >= b ? "YES" : "NO");
    }
    return 0;
}
