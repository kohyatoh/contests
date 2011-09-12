#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
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
#include <functional>
#include <complex>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#define DBG(...) (fprintf(stderr,"%d: ",__LINE__)+fprintf(stderr,__VA_ARGS__))
#else
#define LOG(...) ((void)0)
#define ASS(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF MY_INFINITY

int n, h, memo[10000];
vector<int> g[10000];
vector<int> ans;

int rec(int cur, int pre) {
    LOG(cur);
    if(memo[cur]) return memo[cur];
    int mx=0, s=0;
    rep(i, g[cur].size()) if(g[cur][i]!=pre) {
        const int a = rec(g[cur][i], cur);
        s += a;
        mx = max(mx, a);
    }
    s++; // self
    mx = max(mx, n-s);
    if(mx<=h) ans.push_back(cur);
    return memo[cur] = s;
}

int main() {
    scanf("%d", &n);
    h = n/2;
    rep(i, n-1) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rec(0, -1);
    sort(ans.begin(), ans.end());
    if(ans.empty()) puts("NONE");
    else rep(i, ans.size()) printf("%d\n", ans[i]+1);
    return 0;
}


