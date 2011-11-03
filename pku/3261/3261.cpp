#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

template<class T>
class PatternNumbering {
    int n;
    vector<T> a;
    vector<vector<int> > rs;
    static vector<int> renumbering(vector<pair<pair<int, int>, int> >& xs) {
        sort(xs.begin(), xs.end());
        vector<int> r(xs.size());
        r[xs[0].second] = 0;
        rep(i, xs.size()-1) {
            r[xs[i+1].second] = r[xs[i].second]+(xs[i].first!=xs[i+1].first);
        }
        return r;
    }
    void build() {
        vector<pair<pair<int, int>, int> > xs(n);
        rep(i, n) xs[i] = mp(mp((int)a[i], 0), i);
        rs.push_back(renumbering(xs));
        for(int m=1; (1<<m)<=n; m++) {
            const int k = 1<<m;
            rep(i, n-k+1) xs[i] = mp(mp(rs[m-1][i], rs[m-1][i+k/2]), i);
            xs.resize(n-k+1);
            rs.push_back(renumbering(xs));
        }
    }
public:
    PatternNumbering(const vector<T>& _a) : n(_a.size()), a(_a) {
        build();
    }
    vector<int> numbering(int r) const {
        int m = 0;
        while((2<<m)<r) m++;
        vector<pair<pair<int, int>, int> > xs(n-r+1);
        const int b = r-(1<<m);
        rep(i, n-r+1) xs[i] = mp(mp(rs[m][i], rs[m][i+b]), i);
        return renumbering(xs);
    }
};

int n, K, a[30000], cnt[30000];

bool ok(const PatternNumbering<int>& pn, int L) {
    vector<int> xs(pn.numbering(L));
    memset(cnt, 0, sizeof(cnt));
    rep(i, xs.size()) if(++cnt[xs[i]]>=K) return true;
    return false;
}

int solve() {
    vector<int> v;
    rep(i, n) v.push_back(a[i]);
    PatternNumbering<int> pn(v);
    int l = 0, r = n+1;
    while(r-l>1) {
        const int mid = (l+r)/2;
        if(ok(pn, mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    scanf("%d%d", &n, &K);
    if(n==0) return 0;
    rep(i, n) scanf("%d", a+i);
    printf("%d\n", solve());
    return 0;
}
