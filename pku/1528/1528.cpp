#include <stdio.h>

int main() {
    printf("PERFECTION OUTPUT\n");
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) break;
        int c=0;
        for(int i=1; i*i<=n; i++) if(n%i==0) {
            c += i;
            if(i*i!=n) c += n/i;
        }
        c-=n;
        printf("%5d  %s\n", n, c==n?"PERFECT":c<n?"DEFICIENT":"ABUNDANT");
    }
    printf("END OF OUTPUT\n");
}
