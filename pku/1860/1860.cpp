#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, M, S;
double V;
int m, a[300], b[300];
double r[300], c[300];
double dp[300];

int main() {
    scanf("%d%d%d%lf", &N, &M, &S, &V);
    S--;
    rep(i, M) {
        int _a, _b;
        double r1, c1, r2, c2;
        scanf("%d%d%lf%lf%lf%lf", &_a, &_b, &r1, &c1, &r2, &c2);
        _a--, _b--;
        a[m] = _a; b[m] = _b; r[m] = r1; c[m] = c1; m++;
        a[m] = _b; b[m] = _a; r[m] = r2; c[m] = c2; m++;
    }
    bool ok = false;
    dp[S] = V;
    rep(k, N) rep(i, m) {
        const int u = a[i], v = b[i];
        const double nx = (dp[u]-c[i])*r[i];
        if(dp[v] < nx) {
            dp[v] = nx;
            if(k==N-1) ok = true;
        }
    }
    puts(ok ? "YES" : "NO");
    return 0;
}
