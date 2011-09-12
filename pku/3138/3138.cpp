#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int S, T, M, a[200];

int main() {
    for(int _t=0;; _t++) {
        scanf("%d%d%d", &S, &T, &M);
        if(S==0) return 0;
        rep(i, S) a[i] = 0;
        int ans = 0;
        rep(i, S) {
            int id, p, q;
            scanf("%d%d%d", &id, &p, &q);
            ans += p+q;
        }
        rep(i, T) {
            int id, t;
            scanf("%d%d", &id, &t);
            if(t>=M) a[id-1] = 1;
        }
        rep(i, S) ans += a[i];
        printf("Case %d: %d\n", _t+1, ans);
    }
}
