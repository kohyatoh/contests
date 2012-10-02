#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, K, R, of[128], is[128];

int main() {
    scanf("%d%d", &N, &K);
    rep (i, K) {
        int m, b;
        scanf("%d", &m);
        rep (_, m) {
            scanf("%d", &b);
            b--;
            of[b] = i;
        }
    }
    scanf("%d", &R);
    rep (_, R) {
        int p, q;
        scanf("%d%d", &p, &q);
        p--, q--;
        if (of[p] == of[q]) is[p] = is[q] = 1;
    }
    int ans = 0;
    rep (i, N) ans += is[i];
    printf("%d\n", ans);
    return 0;
}
