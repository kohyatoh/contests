#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[20000], b[20000];

void div(int n, int *d, int m) {
    int a = 1;
    rep (i, n) { d[i] = a / m; a = a % m * 10; }
}

void add(int n, int *a, int *b) {
    int c = 0;
    for (int i = n-1; i >= 0; i--) {
        a[i] += b[i] + c;
        c = 0;
        if (a[i] >= 10) a[i] -= 10, c = 1;
    }
}

int main() {
    int n, k, m, r;
    for (;;) {
        scanf("%d%d%d%d", &n, &k, &m, &r);
        if (n == 0) return 0;
        div(r+10, a, n);
        if (m) rep (i, n-1) {
            div(r+10, b, n*(i+1));
            add(r+10, a, b);
        }
        printf("%d.", a[0]);
        rep (i, r) printf("%d", a[i+1]);
        printf("\n");
    }
}
