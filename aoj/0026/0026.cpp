#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[10][10];

int main() {
    int x, y, t;
    while (scanf("%d,%d,%d", &x, &y, &t) != EOF) {
        if (t == 2) {
            rep (i, 10) rep (j, 10) if (abs(x-i)<2 && abs(y-j)<2) a[i][j]++;
        }
        else {
            const int d = t == 1 ? 1 : 2;
            rep (i, 10) rep (j, 10) if (abs(x-i)+abs(y-j) <= d) a[i][j]++;
        }
    }
    int c = 0, m = 0;
    rep (i, 10) rep (j, 10) {
        if (a[i][j] == 0) c++;
        if (a[i][j] > m) m = a[i][j];
    }
    printf("%d\n", c);
    printf("%d\n", m);
    return 0;
}
