#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[1000];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0) return 0;
        rep(i, n) a[i] = 1;
        rep(_, m) {
            int b;
            rep(i, n) {
                scanf("%d", &b);
                a[i] &= b;
            }
        }
        bool any = false;
        rep(i, n) if(a[i]) any = true;
        puts(any ? "yes" : "no");
    }
}
