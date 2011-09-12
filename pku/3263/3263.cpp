#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BIT {
    static const int N=10000;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
} bit;

pair<int, int> q[10000];

int main() {
    int n, I, H, m;
    scanf("%d%d%d%d", &n, &I, &H, &m);
    bit.init();
    rep(i, m) scanf("%d%d", &q[i].first, &q[i].second);
    rep(i, m) if(q[i].first>q[i].second) swap(q[i].first, q[i].second);
    sort(q, q+m);
    m = unique(q, q+m)-q;
    rep(i, m) {
        bit.add(q[i].first, -1);
        bit.add(q[i].second-1, 1);
    }
    rep(i, n) printf("%d\n", H+bit.sum(i));
    return 0;
}
