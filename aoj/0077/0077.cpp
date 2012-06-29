#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    char buf[128];
    while (fgets(buf, 128, stdin) != NULL) {
        for (int i = 0; buf[i] != '\n' && buf[i] != '\r'; i++) {
            if (buf[i] != '@') putchar(buf[i]);
            else {
                const int c = buf[i+1]-'0';
                i += 2;
                rep (_, c) putchar(buf[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
