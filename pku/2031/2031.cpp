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
    int ud[200];
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

int n;
double x[200], y[200], z[200], r[200];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%lf%lf%lf%lf", x+i, y+i, z+i, r+i);
        vector<pair<double, pair<int, int> > > e;
        rep(i, n) rep(j, i) {
            const double d = sqrt(sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]));
            e.push_back(mp(max(d-r[i]-r[j], 0.0), mp(i, j)));
        }
        sort(e.begin(), e.end());
        us.init();
        double ans = 0;
        rep(i, e.size()) {
            const int u = e[i].second.first;
            const int v = e[i].second.second;
            if(us.set(u, v)) ans += e[i].first;
        }
        printf("%.3f\n", ans);
    }
}
