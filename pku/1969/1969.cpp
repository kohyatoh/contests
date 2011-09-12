#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        int i=0;
        while(i*(i+1)/2<n) i++;
        int k = i%2==0 ? n-(i-1)*i/2 : i*(i+1)/2-n+1;
        printf("TERM %d IS %d/%d\n", n, k, i+1-k);
    }
    return 0;
}

