#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define MOD (100000007LL)
typedef long long Int;
inline void add(Int &a, Int b) { a = (a + b) % MOD; }

#define M (100100)

struct BIT {
    static const int N = M*2;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
} bit;

int n;
vector<pair<int, int> > g[M];
vector<Int> gs;
Int ds[M], dg[M], fs[M], fg[M];
int ans[M];

int index(const vector<Int>& xs, Int x) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

void ijk(Int *dp, int st) {
    rep (i, n) dp[i] = 1LL<<62;
    priority_queue<pair<Int, int> > q;
    q.push(mp(0, st));
    while (!q.empty()) {
        pair<Int, int> vv(q.top());
        q.pop();
        const Int cd = -vv.first;
        const int at = vv.second;
        if (dp[at] <= cd) continue;
        dp[at] = cd;
        rep (i, g[at].size()) {
            const int to = g[at][i].first;
            const Int nd = cd + g[at][i].second;
            if (nd < dp[to]) q.push(mp(-nd, to));
        }
    }
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    rep (_, m) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(mp(b, c));
        g[b].push_back(mp(a, c));
    }
    int Q;
    scanf("%d", &Q);
    rep (i, Q) scanf("%lld%lld", fs+i, fg+i);
    ijk(ds, 0);
    ijk(dg, n-1);
    rep (i, n) gs.push_back(dg[i]);
    rep (i, Q) gs.push_back(fg[i]);
    sort(gs.begin(), gs.end());
    gs.erase(unique(gs.begin(), gs.end()), gs.end());
    vector<pair<Int, int> > qs;
    rep (i, Q) qs.push_back(mp(fs[i], i));
    sort(qs.begin(), qs.end());
    vector<pair<Int, Int> > ps;
    rep (i, n) ps.push_back(mp(ds[i], dg[i]));
    sort(ps.begin(), ps.end());
    int j = 0;
    rep (i, Q) {
        while (j < n && ps[j].first <= qs[i].first) {
            bit.add(index(gs, ps[j].second), 1);
            j++;
        }
        ans[qs[i].second] = bit.rsum(index(gs, fg[qs[i].second]), gs.size());
    }
    rep (i, Q) printf("%d\n", ans[i]);
    return 0;
}
