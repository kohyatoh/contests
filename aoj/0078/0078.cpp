#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[16][16];

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) rep (j, n) a[i][j] = 0;
        int x = n/2+1, y = n/2;
        rep (i, n*n) {
            while (a[x][y]) x = (x+1)%n, y = (y+n-1)%n;
            a[x][y] = i+1;
            x = (x+1)%n, y = (y+1)%n;
        }
        rep (i, n) {
            rep (j, n) printf("%4d", a[i][j]);
            printf("\n");
        }
    }
}
