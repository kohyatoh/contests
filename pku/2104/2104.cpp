#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define P (1024)
int n, m, a[100000], b[100000], sorted[100000];

int kount(int x, int l, int r) {
    int c=0;
    while(l<r && l%P) if(a[l++]<=x) c++;
    while(l<r && r%P) if(a[--r]<=x) c++;
    while(l<r) {
        c += upper_bound(sorted+l, sorted+l+P, x)-sorted-l;
        l += P;
    }
    return c;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) scanf("%d", a+i);
    rep(i, n) sorted[i]=a[i];
    rep(i, n) b[i]=a[i];
    for(int i=0; i+P<=n; i+=P) sort(sorted+i, sorted+i+P);
    sort(b, b+n);
    rep(q, m) {
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        int l=-1, r=n-1, mid;
        while(r-l>1) {
            mid = (l+r)/2;
            if(kount(b[mid], i-1, j)<k) l=mid;
            else r=mid;
        }
        printf("%d\n", b[r]);
    }
    return 0;
}

