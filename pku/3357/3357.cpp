#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

struct UnionSet {
    int ud[100];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool set(int x, int y) {
        x = root(x); y = root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) swap(x, y);
            ud[x] += ud[y]; ud[y] = x;
        }
        return x!=y;
    }
} us;

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        int n;
        scanf("%d", &n);
        vector<pair<int, pair<int, int> > > es;
        rep(i, n) rep(j, n) {
            int c;
            scanf(j<n-1 ? " %d," : " %d", &c);
            if(i<j && c) es.push_back(mp(c, mp(i, j)));
        }
        sort(es.begin(), es.end());
        us.init();
        printf("Case %d:\n", _q+1);
        rep(i, es.size()) {
            const int u = es[i].second.first;
            const int v = es[i].second.second;
            if(us.set(u, v)) printf("%c-%c %d\n", u+'A', v+'A', es[i].first);
        }
    }
    return 0;
}
