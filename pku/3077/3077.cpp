#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int t = 10;
        while(n>t) {
            n = (n+t/2)/t*t;
            t *= 10;
        }
        printf("%d\n", n);
    }
    return 0;
}
