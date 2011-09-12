#include <stdio.h>

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        if(n%2) printf("%d\n", n-1);
        else printf("No Solution!\n");
    }
}
