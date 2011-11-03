#include <stdio.h>

int f(int a, int b) {
    if(b!=0) return 0;
    if(a==12) return 24;
    return (a+12)%24;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d:%d", &a, &b);
        printf("%d\n", f(a, b));
    }
    return 0;
}
