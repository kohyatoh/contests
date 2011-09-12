#include <stdio.h>

int main() {
    int n, m, p, c;
    for(;;) {
        scanf("%d%d%d%d", &n, &m, &p, &c);
        if(n==0 && m==0 && p==0 && c==0) return 0;
        printf("%d\n", n+p-m);
    }
}
