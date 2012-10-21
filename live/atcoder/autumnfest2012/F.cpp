#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, ans[20000];
double a[20000];

void solve_a() {
    int k = n-1;
    for (int i = n-1; i > 0; i--) {
        if (a[i] < 1 || i == 1) ans[i] = k--;
    }
    for (int i = n-1; i > 0; i--) {
        if (ans[i] == -1) ans[i] = k--;
    }
}

void solve_b() {
    int k = n-1;
    for (int i = n-1; i > 0; i--) {
        if (a[i] > 1 || i == 1) ans[i] = k--;
    }
    for (int i = n-1; i > 0; i--) {
        if (ans[i] == -1) ans[i] = k--;
    }
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%lf", a+i);
    int c = 0;
    rep (i, n) {
        if (a[i] < 0) c++, a[i] = -a[i];
    }
    memset(ans, -1, sizeof(ans));
    if (c%2 == 0) solve_a();
    else solve_b();
    for (int i = 1; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
