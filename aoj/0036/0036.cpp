#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const char dat[7][4][5] = {
    { "1100", "1100", "0000", "0000" },
    { "1000", "1000", "1000", "1000" },
    { "1111", "0000", "0000", "0000" },
    { "0100", "1100", "1000", "0000" },
    { "1100", "0110", "0000", "0000" },
    { "1000", "1100", "0100", "0000" },
    { "0110", "1100", "0000", "0000" },
};

char f[16][16];

bool match(int k, int x, int y) {
    rep (i, 4) rep (j, 4) if (f[x+i][y+j] != dat[k][i][j]) return false;
    return true;
}

int solve() {
    rep (k, 7) rep (i, 8) rep (j, 8) if (match(k, i, j)) return k;
    return -1;
}

int main() {
    memset(f, '0', sizeof(f));
    while (scanf(" %c", f[0]) != EOF) {
        rep (i, 8) rep (j, 8) if (i || j) scanf(" %c", f[i]+j);
        printf("%c\n", (char)('A'+solve()));
    }
    return 0;
}
