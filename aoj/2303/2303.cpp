#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int N, M, L, P[200], T[200], V[200];
double zp[200][200], zt[200][200];

Int C[100][100];

int main() {
    C[0][0] = 1;
    rep(i, 80) rep(j, 80) C[i+1][j]+=C[i][j], C[i+1][j+1]+=C[i][j];

    scanf("%d%d%d", &N, &M, &L);
    rep(i, N) scanf("%d%d%d", P+i, T+i, V+i);
    rep(i, N) rep(j, M+1) {
        const double p = P[i]/100.0;
        zt[i][j] = (double)L/V[i] + (double)j*T[i];
        zp[i][j] = (double)C[M][j] * pow(p, j) * pow(1-p, M-j);
    }
    rep(i, N) {
        double ans = 0;
        if(V[i]!=0) rep(j, M+1) {
            double f = 1.0;
            rep(k, N) if(i!=k) {
                double p = 0;
                rep(l, M+1) if(zt[i][j]<zt[k][l]) p += zp[k][l];
                f *= p;
            }
            ans += zp[i][j] * f;
        }
        printf("%.9f\n", ans);
    }
    return 0;
}
