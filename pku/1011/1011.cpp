#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[100], u[100];

bool rec(int ix, int cl, int L, int m) {
    if(m==0) return true;
    if(cl==L) return rec(0, 0, L, m-1);
    int bf = -1;
    for(int i=ix; i<n; i++) if(u[i]==0 && cl+a[i]<=L && bf!=a[i]) {
        bf = a[i];
        u[i] = 1;
        const bool r = rec(i+1, cl+a[i], L, m);
        u[i] = 0;
        if(r || (cl==0)) return r;
    }
    return false;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        sort(a, a+n);
        reverse(a, a+n);
        int s = 0;
        rep(i, n) s += a[i];
        for(int i=1; i<=s; i++) if(s%i==0 && s/i<=n) {
            memset(u, 0, sizeof(u));
            if(rec(0, 0, i, s/i)) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
