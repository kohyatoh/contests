#include <stdio.h>

int main() {
    unsigned int n;
    while(scanf("%u", &n)!=EOF) {
        while(n>0) {
            n = (n/9)+(n%9>0);
            if(n<=1) {
                puts("Stan wins.");
                break;
            }
            n = (n/2)+(n%2>0);
            if(n<=1) {
                puts("Ollie wins.");
                break;
            }
        }
    }
    return 0;
}
