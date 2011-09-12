#include <stdio.h>

int r, c, k, b[30];

int main() {
    for(;;) {
        scanf(" R%dC%d", &r, &c);
        if(r==0 && c==0) return 0;
        k = 0;
        do {
            b[k++] = --c%26;
            c /= 26;
        } while(c);
        while(k) putchar(b[--k]+'A');
        printf("%d\n", r);
    }
}
