#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
double a[20];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%lf", a+i);
        sort(a, a+n);
        bool yes=false;
        for(int k=n-1; k>=0; k--) {
            double s=0;
            rep(i, k) s+=a[i];
            if(s>=a[k]) { yes=true; break; }
        }
        puts(yes ? "YES" : "NO");
    }
}
