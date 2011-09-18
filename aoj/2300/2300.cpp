#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline double sq(double a) { return a*a; }

int N, M;
double L[40], A[40], B[40];

int main() {
    scanf("%d%d", &N, &M);
    rep(i, N) scanf("%lf%lf%lf", L+i, A+i, B+i);
    double ans = 0;
    const int nn = 1<<N;
    int b = (1<<M)-1;
    while(b<nn) {
        double s = 0;
        rep(i, N) if(b&(1<<i)) rep(j, i) if(b&(1<<j)) {
            s += sq(L[i]-L[j]) + sq(A[i]-A[j]) + sq(B[i]-B[j]);
        }
        ans = max(ans, s);
        if(b==0) break;
        const int x=b&-b, y=b+x;
        b = ((b&~y)/x >> 1) | y;
    }
    printf("%.9f\n", ans);
    return 0;
}
