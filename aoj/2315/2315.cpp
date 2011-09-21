#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define Z (128)

void mul(double (*a)[Z], const double (*b)[Z]) {
    static double t[Z][Z];
    memset(t, 0, sizeof(t));
    rep(k, Z) rep(i, Z) rep(j, Z) t[i][j] += a[i][k]*b[k][j];
    memcpy(a, t, sizeof(t));
}

void pow(double (*a)[Z], int x) {
    static double p[Z][Z];
    memcpy(p, a, sizeof(p));
    rep(i, Z) rep(j, Z) a[i][j] = i==j ? 1.0 : 0.0;
    rep(b, 32) {
        if(x&(1<<b)) mul(a, p);
        mul(p, p);
    }
}

void eqsolve(int n, double (*a)[Z]) {
    rep(k, n) {
        double mx = -1;
        int ix = -1;
        for(int i=k; i<n; i++) if(mx<fabs(a[i][k])) mx=fabs(a[i][k]), ix=i;
        if(k!=ix) rep(i, n+1) swap(a[k][i], a[ix][i]);
        const double p = a[k][k];
        for(int i=k; i<=n; i++) a[k][i] /= p;
        rep(i, n) if(i!=k) {
            const double d = a[i][k];
            for(int j=k; j<=n; j++) a[i][j] -= d*a[k][j];
        }
    }
}


double solve(int S, int N, int K) {
    static double p[Z][Z], eqs[Z][Z], mat[Z][Z];
    if(N==1) return S%K==0 ? (double)(S/K) : -1.0;

    // calc p
    p[0][0] = 1.0;
    const int M = N*K+1;
    rep(i, K) rep(j, M) rep(k, N) p[i+1][j+k+1] += p[i][j]/N;

    // solve small
    eqs[0][0] = 1;
    for(int k=1; k<M; k++) {
        eqs[k][k] = 1;
        rep(j, M) eqs[k][abs(k-j)] -= p[K][j];
        eqs[k][M] = -1;
    }
    eqsolve(M, eqs);
    if(S<M) return fabs(eqs[S][M]);

    // solve large
    rep(i, M) mat[0][i] = p[K][i+1];
    mat[0][M] = 1;
    rep(i, M-1) mat[i+1][i] = 1;
    mat[M][M] = 1;
    pow(mat, S-M+1);
    double ans = 0;
    rep(i, M) ans += mat[0][i]*fabs(eqs[M-1-i][M]);
    ans += mat[0][M];
    return ans;
}

int main() {
    int S, N, K;
    scanf("%d%d%d", &S, &N, &K);
    double ans = solve(abs(S), N, K);
    if(ans<0) printf("%d\n", -1);
    else printf("%.9f\n", ans);
    return 0;
}
