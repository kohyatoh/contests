#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define fst first
#define snd second

struct unionset {
    int ud[2000];
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

pair<int, pair<int, int> > cs[20000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--, v--;
        cs[i] = mp(c, mp(u, v));
    }
    sort(cs, cs+m);
    us.init();
    int ans = 0;
    vector<pair<int, int> > as;
    rep(i, m) {
        if(us.size(0)==n) break;
        ans = cs[i].fst;
        if(us.set(cs[i].snd.fst, cs[i].snd.snd)) {
            as.push_back(mp(cs[i].snd.fst, cs[i].snd.snd));
        }
    }
    printf("%d\n", ans);
    printf("%d\n", (int)as.size());
    rep(i, as.size()) printf("%d %d\n", as[i].fst+1, as[i].snd+1);
    return 0;
}
