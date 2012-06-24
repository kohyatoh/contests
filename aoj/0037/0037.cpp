#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char *dat = "RDLU";

int w[6][6][4];

int main() {
    rep (i, 9) {
        char t;
        if (i % 2 == 0) {
            rep (j, 4) {
                scanf(" %c", &t);
                if (t == '1') w[i/2][j][0] = w[i/2][j+1][2] = 1;
            }
        }
        else {
            rep (j, 5) {
                scanf(" %c", &t);
                if (t == '1') w[i/2][j][1] = w[i/2+1][j][3] = 1;
            }
        }
    }
    int x = 0, y = 0, d = 0;
    do {
        rep (i, 4) {
            const int nd = (d+i) % 4;
            if (w[y][x][nd]) {
                putchar(dat[nd]);
                x += dx[nd];
                y += dy[nd];
                d = (nd + 3) % 4;
                break;
            }
        }
    } while (x != 0 || y != 0);
    putchar('\n');
    return 0;
}
