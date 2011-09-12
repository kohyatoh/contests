#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[20], m[20];

int main() {
    for(int q=0;; q++) {
        scanf("%d", &n);
        if(n==0) return 0;
        if(q>0) printf("\n");
        rep(i, n) scanf("%d", a+i);
        sort(a, a+n);
        rep(i, n) m[i]=1;
        rep(i, 6) m[i]=0;
        do {
            int c=0;
            rep(i, n) if(m[i]==0) printf("%d%c", a[i], (++c)<6?' ':'\n');
        } while(next_permutation(m, m+n));
    }
}
