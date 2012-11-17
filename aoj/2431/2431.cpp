#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1LL<<60)
typedef long long Int;

struct BIT {
    static const int N = 200000;
    Int x[N];
    void init() {
        rep (i, N) x[i] = -INF;
    }
    void add(int k, Int a) {
        for(; k<N; k|=k+1) x[k] = max(x[k], a);
    }
    Int sum(int k) {
        Int s = -INF;
        for(; k>=0; k=(k&(k+1))-1) s = max(s, x[k]);
        return s;
    }
} bit;

int n, x[200000];

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", x+i);
    Int s = 0;
    rep (i, n) s += x[i];
    bit.init();
    bit.add(0, 0);
    Int ans = 0;
    rep (i, n) {
        const Int cur = bit.sum(x[i]) + x[i];
        bit.add(x[i], cur);
        ans = max(ans, cur);
    }
    cout << s-ans << endl;
    return 0;
}
