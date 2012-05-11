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
#define INF (1<<28)
#define MOD (YOUR_MODULUS)
inline void cmin(int &a, int b) { if (a > b) a = b; }

#define NUM (500000)
int n, m, is[NUM], dp[NUM];
vector<int> g[NUM];

int main() {
    int z;
    scanf("%d%d%d", &n, &m, &z);
    rep (i, z) {
        int a;
        scanf("%d", &a);
        a--;
        is[a] = 1;
    }
    rep (_, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s, t;
    scanf("%d%d", &s, &t);
    s--, t--;
    rep (i, NUM) dp[i] = INF;
    int ans = 0;
    priority_queue<pair<int, int> > q;
    q.push(mp(0, s));
    while (!q.empty()) {
        const pair<int, int> vv(q.top());
        q.pop();
        const int cs = -vv.first;
        const int at = vv.second;
        if (dp[at] <= cs) continue;
        dp[at] = cs;
        ans = max(ans, cs);
        if (at == t) {
            printf("%d\n", ans);
            return 0;
        }
        const int ns = 1 + (is[at] ? 0 : cs);
        rep (i, g[at].size()) {
            const int to = g[at][i];
            if (ns < dp[to]) q.push(mp(-ns, to));
        }
    }
    printf("%d\n", -1);
    return 0;
}

