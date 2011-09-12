#include <stdio.h>

int main() {
    int p, e, i, d;
    for(int q=0;; q++) {
        scanf("%d%d%d%d", &p, &e, &i, &d);
        if(p==-1) return 0;
        p%=23, e%=28, i%=33;
        int k = d>=i ? i+33+(d-i)/33*33 : i;
        while((k-p)%23 || (k-e)%28) k+=33;
        printf("Case %d: the next triple peak occurs in %d days.\n", q+1, k-d);
    }
}
