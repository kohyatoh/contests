#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m, a[1024][1024], b[1024][1024], x[1024], y[1024];
inline int f(int i, int j) { return (a[i][j]+b[i][j]+x[i]+y[j]) % 2; }

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) rep (j, m) scanf("%d", a[i]+j);
    rep (k, n-1) {
        int c = 0;
        rep (i, m) c += f(k, i) != f(k+1, i);
        rep (i, m) if ((f(k, i)==f(k+1, i)) == c%2) b[k+1][i]++, y[i]++;
        x[k+1] = c;
    }
    int s = 0;
    rep (i, m) if (f(0, i)) s++;
    rep (i, m) if (f(0, i) == s%2) rep (k, n) b[k][i]++;
    rep (i, n) rep (j, m) printf("%d%c", b[i][j]%2, "\n "[j+1<m]);
    return 0;
}
