#include <stdio.h>

int h;

int main() {
    while(scanf("%d", &h)!=EOF) if(h<=168) {
        printf("CRASH %d\n", h);
        return 0;
    }
    printf("NO CRASH\n");
    return 0;
}

