#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, T, E, x[128];

bool ok(int t) {
    return T-E <= t && t <= T+E;
}

int solve() {
    rep (i, N) {
        int t = T/x[i]*x[i];
        if (ok(t) || ok(t+x[i])) return i+1;
    }
    return -1;
}

int main() {
    scanf("%d%d%d", &N, &T, &E);
    rep (i, N) scanf("%d", x+i);
    printf("%d\n", solve());
    return 0;
}
