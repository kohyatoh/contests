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
#define pb push_back
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

struct EGraph {
    int n, m;
    vector<int> head, u, v, next;
    EGraph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(int _u, int _v) {
        u.pb(_u); v.pb(_v); next.pb(head[_u]); head[_u] = m++;
    }
};

struct UEGraph : public EGraph {
    UEGraph(int n) : EGraph(n) {}
    void add(int u, int v) { EGraph::add(u, v); EGraph::add(v, u); }
};

pair<int, int> rec(const UEGraph& g, int cur, int pre) {
    vector<pair<int, int> > a;
    for(int x=g.head[cur]; x!=-1; x=g.next[x]) {
        const int v = g.v[x];
        if(v!=pre) a.push_back(rec(g, v, cur));
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int h = 0, ans = 0;
    rep(i, a.size()) h = max(h, a[i].first+1);
    rep(i, a.size()) ans = max(ans, a[i].second);
    if(a.size()>=2) ans = max(ans, a[0].first+a[1].first+2);
    ans = max(ans, h);
    return mp(h, ans);
}

int solve(const UEGraph& g) {
    LOG(rec(g, 0, -1).second);
    return rec(g, 0, -1).second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    scanf("%d", &m);
    int ans = 0;
    rep(_, m) {
        int n;
        scanf("%d", &n);
        UEGraph g(n);
        rep(i, n-1) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            g.add(u, v);
        }
        ans += solve(g);
    }
    printf("%d\n", ans);
    return 0;
}



