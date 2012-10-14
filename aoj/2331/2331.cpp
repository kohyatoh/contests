#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, z[200000];

int main() {
    scanf("%d", &N);
    rep (_, N) {
        int a, b;
        scanf("%d%d", &a, &b);
        z[a]++;
        z[b+1]--;
    }
    int ans = 1, cur = 1;
    rep (i, N+2) {
        cur += z[i];
        if (cur >= i) ans = i;
    }
    printf("%d\n", ans-1);
    return 0;
}
