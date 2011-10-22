#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BIT {
    static const int N = 210000;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
} bit;

int N, p[210000], v[210000], ans[210000];

int main() {
    while(scanf("%d", &N)!=EOF) {
        rep(i, N) scanf("%d%d", p+i, v+i);
        bit.init();
        for(int i=N-1; i>=0; i--) {
            int l = 0, r = N;
            while(r-l>1) {
                const int mid = (l+r)/2;
                if(mid-bit.sum(mid-1)>p[i]) r = mid;
                else l = mid;
            }
            ans[l] = v[i];
            bit.add(l, 1);
        }
        rep(i, N) printf("%d%c", ans[i], i<N-1 ? ' ' : '\n');
    }
    return 0;
}
