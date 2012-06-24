#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cnt[4];

int main() {
    char t[8];
    int x;
    while (scanf("%d,%s", &x, t) != EOF) {
        if (t[1] == 'B') cnt[2]++;
        else if (t[0] == 'A') cnt[0]++;
        else if (t[0] == 'B') cnt[1]++;
        else if (t[0] == 'O') cnt[3]++;
    }
    rep (i, 4) printf("%d\n", cnt[i]);
    return 0;
}
