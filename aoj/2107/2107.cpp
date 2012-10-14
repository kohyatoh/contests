#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void mmul(int n, int (*a)[128], int (*b)[128]) {
    static int t[128][128];
    rep (i, n) rep (j, n) {
        t[i][j] = 0;
        rep (k, n) t[i][j] |= a[i][k]&b[k][j];
    }
    rep (i, n) rep (j, n) a[i][j] = t[i][j];
}

void mpow(int n, int (*a)[128], int x) {
    static int r[128][128];
    rep (i, n) rep (j, n) r[i][j] = i == j;
    rep (i, 32) {
        if (x&(1<<i)) mmul(n, r, a);
        mmul(n, a, a);
    }
    rep (i, n) rep (j, n) a[i][j] = r[i][j];
}

int u[128], v[128], a[128][128];

bool valid(int i, int j) {
    if (i == j) return false;
    if (v[i] != u[j]) return false;
    if (u[i] == v[j]) return false;
    return true;
}

int main() {
    for (;;) {
        int n, m, z, s, d;
        scanf("%d%d%d", &n, &m, &z);
        if (n == 0 && m == 0 && z == 0) return 0;
        int k = 0;
        rep (i, m) {
            scanf("%d%d", &s, &d);
            s--, d--;
            u[k] = s; v[k] = d; k++;
            u[k] = d; v[k] = s; k++;
        }
        rep (i, k) rep (j, k) a[i][j] = valid(i, j);
        mpow(k, a, z-1);
        bool ans = false;
        rep (i, k) rep (j, k) if (a[i][j]) {
            if (u[i] == 0 && v[j] == n-1) ans = true;
        }
        puts(ans ? "yes" : "no");
    }
}
