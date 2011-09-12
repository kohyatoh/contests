#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[100000], s;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &s);
        rep(i, n) scanf("%d", a+i);
        int ix=0, cur=0;
        int ans = n+1;
        rep(i, n) {
            while(ix<n && cur<s) cur += a[ix++];
            if(cur>=s) ans = min(ans, ix-i);
            cur -= a[i];
        }
        if(ans==n+1) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
