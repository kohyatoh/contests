#include <stdio.h>

int a, n, s, e;

int main() {
    for(;;) {
        scanf("%d%d", &a, &n);
        if(a==0 && n==0) return 0;
        while(n--) {
            scanf("%d%d", &s, &e);
            a -= e-s+1;
        }
        printf("%d\n", a+1);
    }
}
