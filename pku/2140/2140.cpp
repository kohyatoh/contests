#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int c=0;
    for(int i=1; ; i++) {
        int t=i*(i-1)/2;
        if(t>=n) break;
        c += (n-t)%i==0;
    }
    printf("%d\n", c);
    return 0;
}

