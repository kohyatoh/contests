#include <stdio.h>

int n, m;
char f[256];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        int s = 0;
        while(n--) {
            int t;
            scanf("%s %d", f, &t);
            s += t;
        }
        printf("%d\n", 3*m-s);
    }
}
