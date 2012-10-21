#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, T, M[32], p[32][32], t[32][32], z[32];

int main() {
    scanf("%d%d", &N, &T);
    rep (i, N) scanf("%d", M+i);
    rep (k, N) rep (i, M[k]) scanf("%d", p[k]+i);
    rep (k, N) rep (i, M[k]) scanf("%d", t[k]+i);
    int ans = 0, cur = 0;
    for (;;) {
        int ix = -1;
        rep (i, N) if (z[i] < M[i]) {
            if (ix == -1 || p[ix][z[ix]] > p[i][z[i]]) ix = i;
        }
        if (ix == -1 || cur + t[ix][z[ix]] > T) break;
        cur += t[ix][z[ix]];
        ans += p[ix][z[ix]];
        if (z[ix]) ans -= p[ix][z[ix]-1];
        z[ix]++;
    }
    printf("%d\n", ans);
    return 0;
}
