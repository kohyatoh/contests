#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char op[10];
int f[128][128];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int x, y, L;
        scanf("%s%d%d%d", op, &x, &y, &L);
        x--, y--;
        if(op[0]=='T') {
            int s = 0;
            rep(i, L) rep(j, L) s += f[x+i][y+j];
            printf("%d\n", s);
        }
        else {
            const int col = op[0]=='B';
            rep(i, L) rep(j, L) f[x+i][y+j] = col;
        }
    }
    return 0;
}
