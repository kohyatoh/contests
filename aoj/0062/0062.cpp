#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char buf[16];
int a[10];

int main() {
    while (scanf("%s", buf) != EOF) {
        rep (i, 10) a[i] = buf[i] - '0';
        rep (k, 9) rep (i, 9-k) a[i] = (a[i]+a[i+1]) % 10;
        printf("%d\n", a[0]);
    }
    return 0;
}
