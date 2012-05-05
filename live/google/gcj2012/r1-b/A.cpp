#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, s[500];

bool can(int ix, double f) {
    int sum = 0;
    rep (i, N) sum += s[i];
    double my = s[ix] + sum * f;
    double nes = 0;
    rep (i, N) if (i != ix) {
        if (s[i] < my) {
            nes += (my-s[i]) / sum;
        }
    }
    return nes >= 1.0 - f;
}

double calc(int ix) {
    double l = 0, r = 1.0;
    rep (_, 100) {
        double mid = (l+r) / 2.0;
        if (can(ix, mid)) r = mid;
        else l = mid;
    }
    return r;
}

void solve() {
    rep (i, N) printf(" %.12f", calc(i)*100);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d", &N);
        rep (i, N) scanf("%d", s+i);
        printf("Case #%d:", _q+1);
        solve();
    }
    return 0;
}
