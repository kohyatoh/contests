#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, c=0;
        scanf("%d", &n);
        while(n>0) {
            n /= 5;
            c += n;
        }
        printf("%d\n", c);
    }
    return 0;
}
