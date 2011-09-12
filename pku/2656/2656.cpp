#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    for(;;) {
        int n, s1, s2, ms=8, mi=-1;
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) {
            scanf("%d%d", &s1, &s2);
            if(ms<s1+s2) ms=s1+s2, mi=i;
        }
        printf("%d\n", mi+1);
    }
}
