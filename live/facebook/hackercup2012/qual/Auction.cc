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
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<30)
#define MOD (YOUR_MODULUS)
#define fst first
#define snd second

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct RMQ {
    int n;
    vector<pair<int, int> > dat;
    void init(int k) {
        n = 1;
        while (n < k) n *= 2;
        dat.resize(2*n);
        rep(i, 2*n) dat[i] = mp(INF, -1);
    }
    void update(int k, pair<int, int> a) {
        k += n-1;
        dat[k] = a; // overwrite
        //dat[k] = min(dat[k], a); // update
        while (k > 0) {
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    pair<int, int> _q(int a, int b, int k, int l, int r) const {
        if (r<=a || b<=l) return mp(INF, -1);
        if (a<=l && r<=b) return dat[k];
        else return min(_q(a, b, k*2+1, l, (l+r)/2),
                        _q(a, b, k*2+2, (l+r)/2, r));
    }
    pair<int, int> query(int a, int b) const { return _q(a, b, 0, 0, n); }
};

Int N, M, K, P1, W1, A, B, C, D;
int ord[10001000];

struct Seq {
    Int a, b;
    int m, y;
    vector<int> xs;
    Seq(int p1, Int a, Int b, int m) : a(a), b(b), m(m) {
        memset(ord, -1, sizeof(ord));
        int p = p1;
        while (ord[p] == -1) {
            ord[p] = xs.size();
            xs.push_back(p);
            p = (a*p+b)%m + 1;
        }
        y = ord[p];
    }
    int loop_size() const {return xs.size()-y; }
    int at(int ix) const {
        return ix < y ? xs[ix] : xs[y + (ix-y)%loop_size()];
    }
};

vector<RMQ> rmq[2];

void create_rmq(const Seq *ps, const Seq *qs) {
    Int Af = 1, Bf = 0;
    rep (_, ps->loop_size()) {
        Bf = (qs->a * Bf + qs->b + 1) % qs->m;
        Af = Af * qs->a % qs->m;
    }
    const int g = gcd(ps->loop_size(), qs->loop_size());
    const int L = qs->loop_size() / g;
    rmq[0].resize(g);
    rmq[1].resize(g);
    rep (k, g) {
        rmq[0][k].init(L*2);
        rmq[1][k].init(L*2);
        int q = qs->at(qs->y + k);
        rep (i, L) {
            ord[q] = i;
            rmq[0][k].update(i, mp(q, i));
            rmq[0][k].update(i+L, mp(q, i+L));
            rmq[1][k].update(i, mp(-q, i));
            rmq[1][k].update(i+L, mp(-q, i+L));
            q = (Af * q + Bf) % qs->m;
            if (q == 0) q += qs->m;
        }
    }
}

pair<Int, Int> solve() {
    const Seq *ps = new Seq(P1, A, B, M);
    const Seq *qs = new Seq(W1, C, D, K);
    cerr << ps->loop_size() << ", " << qs->loop_size() << endl;
    if (ps->y < qs->y) swap(ps, qs);

    vector<pair<int, pair<int, Int> > > cs;
    rep (i, ps->xs.size()) {
        if (i >= N) break;
        const Int c = i < ps->y ? -1LL : (N - i - 1) / ps->loop_size() + 1;
        cs.push_back(mp(ps->xs[i], mp(i, c)));
    }
    sort(cs.begin(), cs.end());

    create_rmq(ps, qs);
    delete ps;

    const int g = gcd(ps->loop_size(), qs->loop_size());
    const int L = qs->loop_size()/g;
    Int ans[2];
    rep (k, 2) {
        ans[k] = 0;
        int h = INF;
        rep (i, cs.size()) {
            const int ix = cs[i].snd.fst;
            const Int cnt = cs[i].snd.snd;
            if (cnt == -1) {
                const int q = k==0 ? qs->xs[ix] : -qs->xs[ix];
                if (h > q) {
                    h = q;
                    ans[k] += 1;
                }
            }
            else {
                const RMQ& r = rmq[k][(ix-qs->y)%g];
                const int x = ord[qs->at(ix)];
                pair<int, int> mini = r.query(x, x+min(cnt, (Int)L));
                if (h > mini.fst) {
                    h = mini.fst;
                    ans[k] += (x+cnt-mini.snd-1)/L + 1;
                }
            }
        }
        reverse(cs.begin(), cs.end());
    }
    delete qs;
    return mp(ans[0], ans[1]);
}

int main() {
    int T;
    cin >> T;
    rep (t, T) {
        cin >> N >> P1 >> W1 >> M >> K >> A >> B >> C >> D;
        const pair<Int, Int> ans = solve();
        cout << "Case #" << (t+1) << ": " << ans.snd << ' ' << ans.fst << endl;
    }
    return 0;
}
