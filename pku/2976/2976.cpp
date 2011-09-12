#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, a[1000], b[1000];
double t[1000];

int main() {
    for(;;) {
        scanf("%d%d", &n, &k);
        if(n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        rep(i, n) scanf("%d", b+i);
        double l=0, r=1;
        rep(z, 100) {
            double mid=(l+r)/2;
            rep(i, n) t[i]=a[i]-mid*b[i];
            sort(t, t+n);
            double s=0;
            for(int i=k; i<n; i++) s+=t[i];
            if(s>0) l=mid;
            else r=mid;
        }
        printf("%.0f\n", l*100);
    }
}

