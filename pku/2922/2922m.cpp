#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
#define INF (1<<28)

struct UnionSet {
    int ud[100*128];
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

int n, h[100][128];
vector<pair<int, int> > hs[201];

inline int enc(int x, int y) { return x*128+y; }

int solve() {
    rep(i, 201) hs[i].clear();
    rep(i, n) rep(j, n) hs[h[i][j]].push_back(mp(i, j));
    int ans = INF;
    rep(k, 201) if(hs[k].size()) {
        if(k>h[0][0] || k>h[n-1][n-1]) break;
        us.init();
        for(int i=k; i<201 && i-k<ans; i++) if(hs[i].size()) {
            rep(j, hs[i].size()) {
                const int x = hs[i][j].fst, y = hs[i][j].snd, ix = enc(x, y);
                if(x>0 && k<=h[x-1][y] && h[x-1][y]<=i) us.set(ix, enc(x-1, y));
                if(y>0 && k<=h[x][y-1] && h[x][y-1]<=i) us.set(ix, enc(x, y-1));
                if(x<n-1 && k<=h[x+1][y] && h[x+1][y]<=i) us.set(ix, enc(x+1, y));
                if(y<n-1 && k<=h[x][y+1] && h[x][y+1]<=i) us.set(ix, enc(x, y+1));
            }
            if(us.same(enc(0, 0), enc(n-1, n-1))) {
                ans = min(ans, i-k);
                break;
            }
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        scanf(" %d", &n);
        rep(i, n) rep(j, n) scanf(" %d", h[i]+j);
        printf("Scenario #%d:\n", _q+1);
        printf("%d\n", solve());
        printf("\n");
    }
    return 0;
}
