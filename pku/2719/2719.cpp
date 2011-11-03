#include <stdio.h>

int d2i(char ch) { return ch<'4' ? ch-'0' : ch-'1'; }

int main() {
    char s[40];
    for(;;) {
        scanf("%s", s);
        int a = 0;
        for(int i=0; s[i]; i++) a = a*9+d2i(s[i]);
        if(a==0) return 0;
        printf("%s: %d\n", s, a);
    }
}
