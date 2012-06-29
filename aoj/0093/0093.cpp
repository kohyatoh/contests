#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool leap(int y) {
    if (y%4) return false;
    if (y%400==0) return true;
    return y%100;
}

int main() {
    for (int _q = 0;; _q++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0) return 0;
        if (_q) puts("");
        int c = 0;
        for (int i = a; i <= b; i++) if (leap(i)) {
            printf("%d\n", i);
            c++;
        }
        if (c == 0) puts("NA");
    }
    return 0;
}

