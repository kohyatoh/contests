#include <stdio.h>

int main() {
    int n, k;
    while(scanf("%d%d", &n, &k)!=EOF) {
        int s=0;
        while(n>=k) { s+=n/k*k; n=n/k+n%k; }
        printf("%d\n", n+s);
    }
    return 0;
}
