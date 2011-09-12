#include <stdio.h>

long long a[100];

int main() {
    a[0]=9;
    for(int i=1; i<16; i++) a[i]=a[i-1]*(i%2?2:9);
    unsigned int n;
    while(scanf("%u", &n)!=EOF) {
        int ix=0;
        while(a[ix]<n) ix++;
        puts(ix%2 ? "Ollie wins." : "Stan wins.");
    }
    return 0;
}
