#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[1000], b[1000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        rep(i, n) scanf("%d", b+i);
        sort(a, a+n);
        sort(b, b+n);
        int w=0;
        for(int il=0, jl=0, ir=n-1, jr=n-1; il<=ir; ) {
            if(a[ir]>b[jr]) w++, ir--, jr--;
            else if(a[ir]<b[jr] || a[il]<=b[jl]) w-=(a[il]<b[jr]), il++, jr--;
            else w++, il++, jl++;
        }
        printf("%d\n", w*200);
    }
}
