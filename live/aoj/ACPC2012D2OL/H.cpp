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

#define M (300000)

struct unionset {
    int ud[M];
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

pair<int, pair<int, int> > es[M];

int main() {
    int n;
    scanf("%d", &n);
    rep (i, n-1) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        es[i] = mp(c, mp(a, b));
    }
    us.init();
    sort(es, es+n-1);
    Int ans = 0;
    rep (i, n-1) {
        const int a = es[i].second.first;
        const int b = es[i].second.second;
        ans += (Int)es[i].first * us.size(a) * us.size(b);
        us.set(a, b);
    }
    cout << ans << endl;
    return 0;
}

