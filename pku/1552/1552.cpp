#include <stdio.h>
#define rep(i, n) for(int i=0; i<n; i++)

int a[20], n;

int main() {
    for(;;) {
        n=0;
        for(;;) {
            scanf("%d", a+n);
            if(a[n]==0) break;
            if(a[n]==-1) return 0;
            n++;
        }
        int c=0;
        rep(i, n) rep(j, n) if(a[i]==a[j]*2) c++;
        printf("%d\n", c);
    }
}
