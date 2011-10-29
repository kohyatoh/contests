#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char f[16][16];
int xof[27][9], yof[27][9];

bool fix() {
    bool any = false;
    rep(k, 27) {
        int c = 0, x = 0;
        rep(i, 9) {
            c += f[xof[k][i]][yof[k][i]]!='0';
            x += (i+1)-(f[xof[k][i]][yof[k][i]]-'0');
        }
        if(c==8) {
            any = true;
            rep(i, 9) if(f[xof[k][i]][yof[k][i]]=='0') {
                f[xof[k][i]][yof[k][i]] = '0'+x;
            }
        }
    }
    return any;
}

int main() {
    rep(i, 9) rep(j, 9) xof[i][j] = i, yof[i][j] = j;
    rep(i, 9) rep(j, 9) xof[9+i][j] = j, yof[9+i][j] = i;
    rep(i, 9) {
        const int x = i%3*3, y = i/3*3;
        rep(j, 9) xof[18+i][j] = x+j%3, yof[18+i][j] = y+j/3;
    }
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        rep(i, 9) rep(j, 9) scanf(" %c", f[i]+j);
        while(fix());
        printf("Scenario #%d:\n", _q+1);
        rep(i, 9) {
            rep(j, 9) putchar(f[i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
