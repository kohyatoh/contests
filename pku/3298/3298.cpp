#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BIT {
    static const int N=40000;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void set(int k, int a) { for(; k<N; k|=k+1) x[k]=std::max(x[k], a); }
    int max(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s=std::max(s, x[k]); return s; }
} l, r;

int n, a[40000];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        rep(i, n) a[i]--;
        l.init();
        r.init();
        int ans = 0;
        rep(i, n) {
            const int lm=l.max(n-1-a[i]), rm=r.max(a[i]);
            ans = max(ans, rm+1);
            l.set(n-1-a[i], rm+1);
            if(lm > 0) {
                ans = max(ans, lm+1);
                r.set(a[i], lm+1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
