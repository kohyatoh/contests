#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, x[20], y[20], z[20];
char name[20][16];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==-1) return 0;
        rep(i, n) scanf("%d%d%d%s", x+i, y+i, z+i, name[i]);
        int s = 0;
        rep(i, n) s += x[i]*y[i]*z[i];
        const int avg = s/n;
        int bully = -1, victim = -1;
        rep(i, n) {
            const int g = x[i]*y[i]*z[i];
            if(g>avg) bully = i;
            if(g<avg) victim = i;
        }
        printf("%s took clay from %s.\n", name[bully], name[victim]);
    }
}
