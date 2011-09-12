#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
 
typedef unsigned Int;
int n;
Int a[250000];

Int select(int k) {
    int l=0, r=n-1;
    while(l<r) {
        Int p=a[(l+r)/2];
        int i=l-1, j=r+1;
        for(;;) {
            while(a[++i]<p);
            while(a[--j]>p);
            if(i>=j) break;
            std::swap(a[i], a[j]);
        }
        if(i==j && i==k) return a[k];
        if(k<i) r=i-1;
        else l=j+1;
    }
    return a[k];
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%u", a+i);
    if(n%2) printf("%.1f\n", 1.0*select(n/2));
    else printf("%.1f\n", (1.0*select(n/2-1)+select(n/2))/2);
    return 0;
}
