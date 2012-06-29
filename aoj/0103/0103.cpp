#include <stdio.h>

int main() {
    int T;
    char op[16];
    scanf("%d", &T);
    while (T--) {
        int out = 0, r = 0, p = 0;
        while (out < 3) {
            scanf("%s", op);
            if (op[0] == 'O') out++;
            else if (op[1] == 'O') { p += r+1; r = 0; }
            else if (op[1] == 'I') { r++; if (r == 4) r--, p++; }
        }
        printf("%d\n", p);
    }
    return 0;
}
