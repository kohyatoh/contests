#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
typedef vector<vector<double> > mat;
inline mat zero() { return mat(n, vector<double>(n, 0)); }
mat eye() { mat r(zero()); rep(i, n) r[i][i]=1; return r; }
mat add(mat a, const mat& b) {
    rep(i, n) rep(j, n) a[i][j]+=b[i][j];
    return a;
}
mat mul(const mat& a, const mat& b) {
    mat r(zero());
    rep(i, n) rep(j, n) rep(k, n) r[i][j]+=a[i][k]*b[k][j];
    return r;
}
mat pow(mat a, int x) {
    mat r(eye());
    rep(i, 20) {
        if(x&(1<<i)) r = mul(r, a);
        a = mul(a, a);
    }
    return r;
}

int main() {
    for(;;) {
        int C, N, M;
        scanf("%d", &C);
        if(C==0) return 0;
        scanf("%d%d", &N, &M);
        if(M>C) printf("%.3f\n", 0.0);
        else {
            n = C+1;
            mat a(zero());
            rep(i, n) {
                if(i!=0) a[i-1][i] = 1.0*i/C;
                if(i!=C) a[i+1][i] = 1.0*(C-i)/C;
            }
            mat r(pow(a, N));
            printf("%.3f\n", r[M][0]);
        }
    }
}

