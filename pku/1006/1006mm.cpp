#include <stdio.h>

int main() {
    int p, e, i, d;
    for(int q=0;; q++) {
        scanf("%d%d%d%d", &p, &e, &i, &d);
        if(p==-1) return 0;
        p%=23, e%=28, i%=33;
        int x = p + 253*(e-p);
        int y = x + 1288*(i-x);
        int z = y + 21252 * (d>=y ? 1+(d-y)/21252 : -((y-d-1)/21252));
        printf("Case %d: the next triple peak occurs in %d days.\n", q+1, z-d);
    }
}
