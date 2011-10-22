#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BIT {
    static const int N=1000000;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
} bit;

int main() {
    int N, S;
    scanf("%d%d", &N, &S);
    int ans = 0;
    rep(i, N) {
        int a;
        scanf("%d", &a);
        if(a<S) ans += bit.sum(S-a);
        bit.add(a, 1);
    }
    printf("%d\n", ans);
    return 0;
}
