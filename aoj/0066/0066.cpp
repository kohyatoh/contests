#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool win(const char *f, char m) {
    if (f[0] == m && f[1] == m && f[2] == m) return true;
    if (f[3] == m && f[4] == m && f[5] == m) return true;
    if (f[6] == m && f[7] == m && f[8] == m) return true;
    if (f[0] == m && f[3] == m && f[6] == m) return true;
    if (f[1] == m && f[4] == m && f[7] == m) return true;
    if (f[2] == m && f[5] == m && f[8] == m) return true;
    if (f[0] == m && f[4] == m && f[8] == m) return true;
    if (f[2] == m && f[4] == m && f[6] == m) return true;
    return false;
}

int main() {
    char f[16];
    while (scanf("%s", f) != EOF) {
        if (win(f, 'o')) puts("o");
        else if (win(f, 'x')) puts("x");
        else puts("d");
    }
    return 0;
}
