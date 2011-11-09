#include <stdio.h>
#include <math.h>

int dig[10000001];

int main() {
    double d = 0;
    for(int i=1; i<=10000000; i++) {
        d += log10((double)i);
        dig[i] = d+1;
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dig[n]);
    }
    return 0;
}
