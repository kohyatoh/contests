#include <stdio.h>

int J(int n, int m) {
    if (n == 1) return 0;
    return (J(n-1, m) + m) % n;
}

int main() {
    for (;;) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) return 0;
        printf("%d\n", J(n, m) + 1);
    }
}
