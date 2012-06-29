#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cnt[128];

int main() {
    int u, v;
    while (scanf("%d%d", &u, &v) != EOF) {
        u--, v--;
        rep (i, 128) cnt[i] = 0;
        cnt[u]++, cnt[v]++;
        for (;;) {
            scanf("%d%d", &u, &v);
            if (u == 0 && v == 0) break;
            u--, v--;
            cnt[u]++, cnt[v]++;
        }
        bool f = true;
        rep (i, 128) if (cnt[i]%2 != (i<2)) f = false;
        puts(f ? "OK" : "NG");
    }
    return 0;
}
