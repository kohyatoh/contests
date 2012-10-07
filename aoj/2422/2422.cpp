#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, c[12], d, head;
int memo[12][48][5][5];

bool rec(int at, int r, int x, int y) {
    if (at == 12) return r == 0 && x == 0 && y == 0;
    if (memo[at][r][x][y] != -1) return memo[at][r][x][y];
    bool ans = false;
    rep (p, 2) rep (q, 5) {
        const int use = x + y + q + p*3 + 2*(head == at);
        if (use > 4 || use > c[at]+r || use < c[at]) continue;
        if (rec(at+1, r-use+c[at], y, q)) { ans = true; goto ret; }
    }
ret:
    return (memo[at][r][x][y] = ans);
}

bool solve() {
    rep (k, 12) {
        head = k;
        memset(memo, -1, sizeof(memo));
        if (rec(0, d, 0, 0)) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    rep (i, 3*n+1) {
        char buf[8];
        scanf("%s", buf);
        if (buf[0] == '*') d++;
        else c[atoi(buf)-1]++;
    }
    bool some = false;
    rep (i, 12) {
        c[i]++;
        if (solve()) printf("%d\n", i+1), some = true;
        c[i]--;
    }
    if (!some) printf("%d\n", -1);
    return 0;
}
