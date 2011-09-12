#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int k, m, c, r, a, s[10000];

int main() {
    for(int q=1;; q++) {
        scanf("%d", &k);
        if(k==0) return 0;
        scanf("%d", &m);
        rep(i, k) {
            scanf("%d", &a);
            s[a]=q;
        }
        bool yes=true;
        rep(i, m) {
            scanf("%d%d", &c, &r);
            rep(j, c) {
                scanf("%d", &a);
                if(s[a]==q) r--;
            }
            if(r>0) yes=false;
        }
        puts(yes ? "yes" : "no");
    }
}

