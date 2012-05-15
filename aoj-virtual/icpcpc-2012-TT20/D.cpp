#include <stdio.h>
#include <string.h>
#include <assert.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int memo[1024][1024];
int S(int n, int m) {
    if (n == 0 && m == 0) return 1;
    if (n == 0 || m == 0) return 0;
    if (memo[n][m] != -1) return memo[n][m];
    return memo[n][m] = (m * S(n-1, m) + S(n-1, m-1)) % 2;
}

int SS(int n, int m) {
    if (m == 0) return n == 0;
    if (n < m) return 0;
    n -= m;
    m = (m-1) / 2;
    while (n >= 4 || m >= 4) {
        long long k = 4;
        while (k*2 <= n || k*2 <= m) k *= 2;
        if (n >= k && m >= k) return 0;
        if (n >= k) n -= k;
        if (m >= k) m -= k;
    }
    if (n == 0) return 1;
    if (n == 1) return m%2 == 0;
    if (n == 2) return m < 2;
    if (n == 3) return m == 0;
    return -1;
}

int main() {
    memset(memo, -1, sizeof(memo));
//    rep (i, 1000) rep (j, 1000) assert(S(i, j) == SS(i, j));
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", SS(n, m));
    }
    return 0;
}
