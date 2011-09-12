#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[2000];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        sort(a, a+n);
        int ans = 0;
        while(n>3) {
            ans += a[0]+a[n-1]+min(a[0]+a[n-2], 2*a[1]);
            n -= 2;
        }
        if(n==1) ans += a[0];
        else if(n==2) ans += a[1];
        else ans += a[0]+a[1]+a[2];
        printf("%d\n", ans);
    }
    return 0;
}

