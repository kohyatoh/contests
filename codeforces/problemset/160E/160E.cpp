#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (2000000000)

struct V {
    int l, r, t, i;
};

bool operator<(const V& l, const V& r) {
    if (l.l != r.l) return l.l < r.l;
    if (l.t != r.t) return l.t > r.t;
    if (l.r != r.r) return l.r > r.r;
    return l.i < r.i;
}

struct RMQ {
    static const int n = 65536 * 4; // must be 2^k
    int dat[2*n];
    void init() { rep(i, 2*n) dat[i] = INF; }
    void update(int k, int a) {
        k+=n-1;
        //dat[k] = a; // overwrite
        dat[k] = min(dat[k], a); // update
        while(k>0) {
            k=(k-1)/2;
            dat[k]=min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int _q(int a, int b, int k, int l, int r) {
        if(r<=a || b<=l) return INF;
        if(a<=l && r<=b) return dat[k];
        else return min(_q(a, b, k*2+1, l, (l+r)/2),
                        _q(a, b, k*2+2, (l+r)/2, r));
    }
    int query(int a, int b) { return _q(a, b, 0, 0, n); }
} rmq;

int ans[200000];
V vs[200000];
vector<int> ts;

inline int of(int t) {
    return lower_bound(ts.begin(), ts.end(), t) - ts.begin();
}

int main() {
    rmq.init();
    int N, M;
    scanf("%d%d", &N, &M);
    map<int, int> bus;
    rep (i, N) {
        scanf("%d%d%d", &vs[i].l, &vs[i].r, &vs[i].t);
        vs[i].i = -i-1;
        ts.push_back(vs[i].t);
        bus[vs[i].t] = i+1;
    }
    rep (i, M) {
        scanf("%d%d%d", &vs[N+i].l, &vs[N+i].r, &vs[N+i].t);
        vs[N+i].i = i;
        ts.push_back(vs[N+i].t);
    }
    sort(ts.begin(), ts.end());
    ts.erase(unique(ts.begin(), ts.end()), ts.end());
    const int L = ts.size();
    const int n = N+M;
    sort(vs, vs+n);
    rep (i, n) {
        if (vs[i].i < 0) rmq.update(of(vs[i].t), -vs[i].r);
        else {
            const int t = of(vs[i].t);
            int l = t, r = L;
            if (-rmq.query(t, r) < vs[i].r) ans[vs[i].i] = -1;
            else {
                while (r - l > 1) {
                    const int mid = (l+r) / 2;
                    if (-rmq.query(t, mid) < vs[i].r) l = mid;
                    else r = mid;
                }
                ans[vs[i].i] = bus[ts[l]];
            }
        }
    }
    rep (i, M) printf("%d%c", ans[i], "\n "[i+1<M]);
    return 0;
}
