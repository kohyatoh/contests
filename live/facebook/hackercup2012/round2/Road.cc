#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
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
#define INF (1<<28)
#define MOD (YOUR_MODULUS)

struct UnionSet {
    int ud[50000];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if (x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} cc, us;

int N, M, K;
vector<int> g[20000];

int main() {
    int T;
    scanf("%d", &T);
    rep (t, T) {
        rep (i, 20000) g[i].clear();
        scanf("%d%d%d", &N, &M, &K);
        cc.init();
        int del = 0;
        rep (i, M) {
            int a, b;
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
            if (a >= K && b >= K) cc.set(a, b);
        }
        for (int i = K; i < N; i++) if (cc.root(i) != i) {
            const int r = cc.root(i);
            rep (j, g[i].size()) if (g[i][j] < K) g[r].push_back(g[i][j]);
        }
        for (int i = K; i < N; i++) if (cc.root(i) == i) {
            sort(g[i].begin(), g[i].end());
            int m = 0;
            rep (j, g[i].size()) {
                const int t = g[i][j];
                if (t < K) {
                    if (j && g[i][j] == g[i][j-1]) del++;
                    else g[i][m++] = t;
                }
            }
            g[i].resize(m);
        }
        rep (i, K) {
            rep (j, g[i].size()) g[i][j] = cc.root(g[i][j]);
            sort(g[i].begin(), g[i].end());
            g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        }
        rep (i, N) if (cc.root(i) == i) {
            LOG(i);
            rep (j, g[i].size()) LOG(g[i][j]);
        }
        LOG(del);
        us.init();
        int cn = 0, cm = 0;
        rep (i, N) if (cc.root(i) == i) {
            cn++;
            rep (j, g[i].size()) us.set(i, g[i][j]), cm++;
        }
        LOG(cn);
        assert(cm%2==0);
        cm /= 2;
        LOG(cm);
        int c = cn;
        rep (i, N) if (cc.root(i) == i && us.root(i) == i) {
            c--;
        }
        printf("Case #%d: %d\n", t+1, del+cm-c);
    }
    return 0;
}
