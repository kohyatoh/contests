#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int w, h;
char inst[20], f[20][20];

int main() {
    for(;;) {
        scanf("%s", inst);
        if(inst[0]=='E') return 0;
        scanf("%d%d", &w, &h);
        rep(i, w) scanf("%s", f[i]);
        scanf("%s", inst);
        rep(i, w-1) {
            rep(j, h-1) putchar((f[i][j]+f[i][j+1]+f[i+1][j]+f[i+1][j+1])/4);
            putchar('\n');
        }
    }
}

