#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        puts(n>2?"Bob":"Alice");
    }
}
