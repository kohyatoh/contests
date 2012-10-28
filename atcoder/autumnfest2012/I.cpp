#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define P (1000000007LL)
#define MOD (1000000009LL)
#define L (1024)
int N, M, Q;
int a1, Amul, Aadd;
int b1, Bmul, Badd;
int d1, Dmul, Dadd;
int p[3*L][3*L], q[3*L][3*L], f[3*L][3*L];

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    scanf("%d%d%d", &a1, &Amul, &Aadd);
    scanf("%d%d%d", &b1, &Bmul, &Badd);
    scanf("%d%d%d", &d1, &Dmul, &Dadd);
    const int Dmod = N > M ? N : M;
    long long a = a1, b = b1, d = d1;
    rep (_, Q) {
        p[L+a-d+1][L+b] += 1; p[L+a+1][L+b-d] -= 1;
        p[L+a+1][L+b+d] += 1; p[L+a+d+1][L+b] -= 1;
        q[L+a-d+1][L+b+1] -= 1; q[L+a+1][L+b+d+1] += 1;
        q[L+a+1][L+b-d+1] -= 1; q[L+a+d+1][L+b+1] += 1;
        a = (a * Amul + Aadd) % N + 1;
        b = (b * Bmul + Badd) % M + 1;
        d = (d * Dmul + Dadd) % Dmod + 1;
    }
    rep (i, 3*L-1) rep (j, 3*L-1) p[i+1][j] += p[i][j+1];
    rep (i, 3*L-1) rep (j, 3*L-1) q[i+1][j+1] += q[i][j];
    rep (i, 3*L) rep (j, 3*L) f[i][j] = p[i][j] + q[i][j];
    rep (i,3*L) rep (j, 3*L-1) f[i][j+1] += f[i][j];
    rep (i,3*L-1) rep (j, 3*L) f[i+1][j] += f[i][j];
    int h = 0;
    rep (i, N) rep (j, M) h = (h*P+f[L+1+i][L+1+j]) % MOD;
    printf("%d\n", h);
    return 0;
}
