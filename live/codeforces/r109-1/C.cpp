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
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<28)
#define MOD (YOUR_MODULUS)

int n, m;
vector<int> f[1001000];

struct sig {
    int len, k;
    unsigned long long h;
} sg[1001000];

inline bool operator<(const sig& l, const sig& r) {
    if (l.len != r.len) return l.len < r.len;
    if (l.h != r.h) return l.h < r.h;
    return f[l.k] < f[r.k];
}

inline bool operator==(const sig& l, const sig& r) {
    return l.len == r.len && l.h == r.h && f[l.k] == f[r.k];
}

unsigned long long hash(const vector<int>& v) {
    unsigned long long h = 0;
    rep (i, v.size()) {
        h = h * 1000009 + v[i];
    }
    return h;
}

Int solve() {
    rep (i, n) sort(f[i].begin(), f[i].end());
    rep (i, n) {
        sg[i].len = f[i].size();
        sg[i].h = hash(f[i]);
        sg[i].k = i;
    }
    sort(sg, sg+n);
    Int c = 1;
    Int ans = 0;
    for (int i = 1; i < n; i++) {
        if (sg[i-1] == sg[i]) c++;
        else {
            ans += c*(c-1)/2;
            c = 1;
        }
    }
    ans += c*(c-1)/2;
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    rep (_, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    Int ans = 0;
    ans += solve();
    rep (i, n) f[i].push_back(i);
    ans += solve();
    cout << ans << endl;
    return 0;
}
