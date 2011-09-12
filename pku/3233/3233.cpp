#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define N (32)

int n, m;

struct MAT {
    int a[N][N];
    MAT& operator+=(const MAT& r) {
        rep(i, n) rep(j, n) a[i][j] = (a[i][j]+r.a[i][j])%m;
        return *this;
    }
    MAT& operator*=(const MAT& r) {
        int t[N][N];
        memset(t, 0, sizeof(t));
        rep(i, n) rep(j, n) rep(k, n) t[i][j]=(t[i][j]+a[i][k]*r.a[k][j])%m;
        memcpy(a, t, sizeof(t));
        return *this;
    }
};
MAT operator+(MAT l, const MAT& r) { return l+=r; }
MAT operator*(MAT l, const MAT& r) { return l*=r; }

MAT r[50];

MAT pow(int x) {
    MAT z;
    memset(z.a, 0, sizeof(z.a));
    rep(i, n) z.a[i][i] = 1;
    rep(i, 32) if(x&(1LL<<i)) z *= r[i];
    return z;
}


MAT f(int k) {
    if(k==1) return r[0];
    const int x = k/2;
    MAT a = f(x);
    if(k%2==1) return a+pow(x)*a+pow(k);
    else return a+pow(x)*a;
}

int main() {
    int k;
    scanf("%d%d%d", &n, &k, &m);
    rep(i, n) rep(j, n) scanf("%d", &r[0].a[i][j]);
    rep(k, 40) {
        r[k+1] = r[k];
        r[k+1] *= r[k];
    }
    MAT ans = f(k);
    rep(i, n) rep(j, n) printf("%d%c", ans.a[i][j], j<n-1 ? ' ' : '\n');
    return 0;
}
