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
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

#define NUM (200000)
int n, m;
int q, h[NUM], cnt[NUM], ans[NUM];
vector<int> g[NUM], id[NUM];
vector<int> p[NUM];
int a[NUM], b[NUM];

void rec(int at, int pre) {
    if (pre != -1) {
        p[at].push_back(pre);
        for (int ch = 1, k = 0; ch*2 <= h[at]; ch *= 2, k++) {
            p[at].push_back(p[p[at][k]][k]);
        }
    }
    rep (i, g[at].size()) if (g[at][i] != pre) {
        const int to = g[at][i];
        h[to] = h[at] + 1;
        rec(to, at);
    }
}

int get(int at, int h) {
    if (h == 0) return at;
    int ch = 1, k = 0;
    while (ch*2 <= h) ch*=2, k++;
    return get(p[at][k], h-ch);
}

int common(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    if (get(a, h[a]-h[b]) == b) return b;
    int l = 0, r = h[b];
    while (r-l > 1) {
        const int mid = (l+r)/2;
        if (get(a, h[a]-mid) == get(b, h[b]-mid)) l = mid;
        else r = mid;
    }
    return get(a, h[a]-l);
}

void solve(int at, int pre) {
    rep (i, g[at].size()) if (g[at][i] != pre) {
        const int to = g[at][i];
        solve(to, at);
        ans[id[at][i]] = cnt[to];
        cnt[at] += cnt[to];
    }
    LOG(at);
    LOG(cnt[at]);
}

int main() {
    scanf("%d", &n);
    rep (i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        id[u].push_back(i);
        g[v].push_back(u);
        id[v].push_back(i);
    }
    scanf("%d", &m);
    rep (i, m) {
        scanf("%d%d", a+i, b+i);
        a[i]--, b[i]--;
    }
    rec(0, -1);
    rep (i, n) LOG(h[i]);
    rep (i, m) {
//        printf("%d, %d -> %d\n", a[i], b[i], common(a[i], b[i]));
        cnt[a[i]]++;
        cnt[b[i]]++;
        cnt[common(a[i], b[i])] -= 2;
    }
    solve(0, -1);
    rep (i, n-1) printf("%d%c", ans[i], "\n "[i+1<n-1]);
    return 0;
}
