#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1LL<<60)
typedef long long Int;

struct RMQ {
    static const int n=65536*2; // must be 2^k
    Int dat[2*n];
    void init() { rep(i, 2*n) dat[i]=INF; }
    void update(int k, Int a) {
        k+=n-1;
        //dat[k] = a; // overwrite
        dat[k] = min(dat[k], a); // update
        while(k>0) {
            k=(k-1)/2;
            dat[k]=min(dat[k*2+1], dat[k*2+2]);
        }
    }
    Int _q(int a, int b, int k, int l, int r) {
        if(r<=a || b<=l) return INF;
        if(a<=l && r<=b) return dat[k];
        else return min(_q(a, b, k*2+1, l, (l+r)/2),
                        _q(a, b, k*2+2, (l+r)/2, r));
    }
    Int query(int a, int b) { return _q(a, b, 0, 0, n); }
} rmq;

int n, m, e;
pair<int, pair<int, int> > a[10000];

int main() {
    scanf("%d%d%d", &n, &m, &e);
    rep(i, n) scanf("%d%d%d", &a[i].second.first, &a[i].first, &a[i].second.second);
    sort(a, a+n);
    rmq.init();
    rmq.update(m, 0);
    rep(i, n) {
        const int l = a[i].second.first;
        const int r = a[i].first+1;
        const int s = a[i].second.second;
        const Int nxt = rmq.query(l, r)+s;
        rmq.update(r, nxt);
    }
    Int ans = rmq.query(e+1, e+2);
    if(ans==INF) ans = -1;
    cout << ans << endl;
    return 0;
}
