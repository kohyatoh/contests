#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char f[32][32];

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        memset(f, '.', sizeof(f));
        int x, y;
        scanf("%d%d", &x, &y);
        for(;;) {
            char op;
            scanf(" %c", &op);
            if(op=='.') break;
            else if(op=='N') f[x][y++] = 'X';
            else if(op=='E') f[x++][y-1] = 'X';
            else if(op=='S') f[x-1][--y] = 'X';
            else if(op=='W') f[--x][y] = 'X';
        }
        printf("Bitmap #%d\n", _q+1);
        rep(i, 32) {
            rep(j, 32) printf("%c", f[j][31-i]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
