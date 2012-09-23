#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fst first
#define snd second
typedef long long Int;

typedef pair<double, double> P;
P mul(const P& p1, const P& p2) {
    return P(p1.fst*p2.fst, p2.fst*p1.snd + p2.snd);
}

struct Seg {
    static const int n=65536*4; // must be 2^k
    P dat[2*n];
    void init() { rep(i, 2*n) dat[i] = P(1.0, 0.0); }
    void update(int k, const P& p) {
        k += n-1;
        dat[k] = p;
        while(k>0) {
            k = (k-1)/2;
            dat[k] = mul(dat[k*2+1], dat[k*2+2]);
        }
    }
    P _q(int a, int b, int k, int l, int r) {
        if(r<=a || b<=l) return P(1.0, 0.0);
        if(a<=l && r<=b) return dat[k];
        else return mul(_q(a, b, k*2+1, l, (l+r)/2), _q(a, b, k*2+2, (l+r)/2, r));
    }
    P query(int a, int b) { return _q(a, b, 0, 0, n); }
} seq;

int N, M;
Int q_p[200000];
double q_a[200000], q_b[200000];
int xn;
Int xs[200000];

int main() {
    scanf("%d%d", &N, &M);
    seq.init();
    rep (i, M) scanf("%lld%lf%lf", q_p+i, q_a+i, q_b+i);
    rep (i, M) xs[i] = q_p[i];
    sort(xs, xs+M);
    xn = unique(xs, xs+M) - xs;
    double cur = 1;
    double lb = cur, ub = cur;
    rep (i, M) {
        const int ix = lower_bound(xs, xs+xn, q_p[i]) - xs;
        seq.update(ix, P(q_a[i], q_b[i]));
        P p = seq.query(0, xn);
        cur = p.fst + p.snd;
        lb = min(lb, cur), ub = max(ub, cur);
    }
    printf("%.9f\n", lb);
    printf("%.9f\n", ub);
    return 0;
}
