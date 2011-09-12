#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct RMQ {
    static const int n=65536;
    int dat[2*n];
    void init() { rep(i, 2*n) dat[i]=INT_MAX; }
    void update(int k, int a) {
        k+=n-1;
        dat[k]=a;
        while(k>0) {
            k=(k-1)/2;
            dat[k]=min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int _q(int a, int b, int k, int l, int r) {
        if(r<=a || b<=l) return INT_MAX;
        if(a<=l && r<=b) return dat[k];
        else return min(_q(a, b, k*2+1, l, (l+r)/2),
                        _q(a, b, k*2+2, (l+r)/2, r));
    }
    int query(int a, int b) { return _q(a, b, 0, 0, n); }
};

int n, q, h[50000];
RMQ mn, mx;

int main() {
    scanf("%d%d", &n, &q);
    rep(i, n) scanf("%d", h+i);
    mn.init();
    mx.init();
    rep(i, n) mn.update(i, h[i]);
    rep(i, n) mx.update(i, -h[i]);
    rep(i, q) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        printf("%d\n", -mx.query(a, b)-mn.query(a, b));
    }
    return 0;
}

