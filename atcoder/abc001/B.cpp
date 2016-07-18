#include <stdio.h>

int vv(int m) {
    if (m < 100) return 0;
    if (m <= 5000) return m / 100;
    if (m <= 30000) return m / 1000 + 50;
    if (m <= 70000) return (m - 30000) / 5000 + 80;
    return 89;
}

int main() {
    int m;
    scanf("%d", &m);
    printf("%02d\n", vv(m));
    return 0;
}
