#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1LL<<60)
#define MOD (YOUR_MODULUS)

#define NUM (200000)

struct BIT {
    static const int N = NUM;
    Int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, Int a) { for(; k<N; k|=k+1) x[k]+=a; }
    Int sum(int k) { Int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
} bit;

int n;
Int K;
Int a[NUM], sum[NUM], xs[NUM];
int rix[NUM];

Int f(Int v) {
    Int ans = 0;
    bit.init();
    rep (r, n) {
        bit.add(rix[r], 1);
        const int ix = upper_bound(xs, xs+n, sum[r+1]-v) - xs;
        if (ix > 0) ans += bit.sum(ix-1);
    }
    return ans;
}

int main() {
    cin >> n >> K;
    rep (i, n) cin >> a[i];
    rep (i, n) sum[i+1] = sum[i] + a[i];
    rep (i, n) xs[i] = sum[i];
    sort(xs, xs+n);
    rep (i, n) rix[i] = lower_bound(xs, xs+n, sum[i]) - xs;
    Int l = -INF, r = INF;
    while (r-l > 1) {
        const Int mid = (l+r) / 2;
        if (f(mid) >= K) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}
