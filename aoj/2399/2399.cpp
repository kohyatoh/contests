#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, a[128][128], b[128];

void readA(int *a) {
    rep (i, n) a[i] = 0;
    int m;
    scanf("%d", &m);
    rep (i, m) {
        int x;
        scanf("%d", &x);
        a[x-1] = 1;
    }
}

bool can(int k) {
    rep (i, n) if (b[i] && !a[k][i]) return false;
    return true;
}

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) readA(a[i]);
        readA(b);
        int c = 0;
        rep (i, n) if (can(i)) c++;
        if (c != 1) printf("%d\n", -1);
        else rep (i, n) if (can(i)) printf("%d\n", i+1);
    }
}
