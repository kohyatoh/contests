#include <stdio.h>

int f0, f1, f2;

int main() {
    while(scanf("%d%d%d", &f0, &f1, &f2)!=EOF) {
        int C = f0;
        int A = (f0+f2-2*f1)/2;
        int B = f1-A-C;
        printf("%d %d %d\n", 9*A+3*B+C, 16*A+4*B+C, 25*A+5*B+C);
    }
    return 0;
}

