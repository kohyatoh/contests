#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
inline double sq(double a) { return a*a; }

struct unionset {
    int ud[1024];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int N, M;
int x[1024], y[1024];

int main() {
    scanf("%d%d", &N, &M);
    rep(i, N) scanf("%d%d", x+i, y+i);
    us.init();
    rep(i, M) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        us.set(u, v);
    }
    vector<pair<double, pair<int, int> > > ps;
    rep(i, N) rep(j, i) {
        ps.push_back(mp(sq(x[i]-x[j])+sq(y[i]-y[j]), mp(i, j)));
    }
    sort(ps.begin(), ps.end());
    double ans = 0;
    for(int i=0; i<(int)ps.size() && us.size(0)<N; i++) {
        const int u = ps[i].second.first;
        const int v = ps[i].second.second;
        if(us.set(u, v)) ans += sqrt(ps[i].first);
    }
    printf("%.2f\n", ans);
    return 0;
}
