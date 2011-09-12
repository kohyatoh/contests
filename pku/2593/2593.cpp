#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define N (100000)
int n, a[N], s[N+1], m[N+1];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        rep(i, n) s[i+1]=s[i]+a[i];
        m[n]=s[n];
        rep(i, n) m[n-i-1]=max(m[n-i], s[n-i-1]);
        int ans=s[n], ms=a[0], mp=0;
        for(int p=1; p<n; p++) {
            ans = max(ans, ms+m[p+1]-s[p]);
            mp = min(mp, s[p]);
            ms = max(ms, s[p+1]-mp);
        }
        printf("%d\n", ans);
    }
}

