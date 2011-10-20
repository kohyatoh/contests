#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

struct MBIT {
    static const int N = 1<<16;
    int x[N];
    void init() {
        rep(i, N) x[i] = INF;
    }
    void update(int k, int a) {
        for(; k<N && x[k]>a; k|=k+1) x[k] = a;
    }
    int min(int k) {
        int s = INF;
        for(; k>=0; k=(k&(k+1))-1) s = std::min(s, x[k]);
        return s;
    }
} bit;

int n, m, a[500000], b[500000];

int main() {
    scanf("%d%d", &n, &m);
    bit.init();
    rep(i, m) scanf("%d%d", a+i, b+i);
    bit.update(n, 0);
    for(int i=m-1; i>=0; i--) {
        bit.update(a[i], bit.min(b[i])+1);
    }
    printf("%d\n", bit.min(1));
    return 0;
}
