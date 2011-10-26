#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char f[128], g[128];

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        scanf("%s%s", f, g);
        const int n = strlen(f), m = strlen(g), L = max(n, m);
        rep(i, n) f[i] -= '0';
        rep(i, m) g[i] -= '0';
        reverse(f, f+n);
        reverse(g, g+m);
        for(int i=0, carry=0; i<=L; i++) {
            const int nc = (f[i]+g[i]+carry)/2;
            f[i] = (f[i]+g[i]+carry)%2;
            carry = nc;
        }
        int k = L;
        while(k>0 && f[k]==0) k--;
        printf("%d ", _q+1);
        while(k>=0) putchar('0'+f[k--]);
        putchar('\n');
    }
    return 0;
}
