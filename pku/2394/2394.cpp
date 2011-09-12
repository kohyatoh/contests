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

int E, u[2000], v[2000], cost[2000], next[2000], head[1000];
void init() { E=0; memset(head, -1, sizeof(head)); }
void add_edge(int _u, int _v, int c) {
    u[E]=_u; v[E]=_v; cost[E]=c; next[E]=head[u[E]]; head[u[E]]=E; E++;
}
int vis[1000];

int main() {
    int F, P, C, M;
    scanf("%d%d%d%d", &F, &P, &C, &M);
    init();
    rep(i, P) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    priority_queue<pair<int, int> > q;
    q.push(mp(0, 0));
    while(!q.empty()) {
        pair<int, int> _v(q.top());
        q.pop();
        const int cur=_v.second, t=-_v.first;
        if(t>M || vis[cur]) continue;
        vis[cur] = 1;
        for(int x=head[cur]; x!=-1; x=next[x]) {
            q.push(mp(-t-cost[x], v[x]));
        }
    }
    vector<int> ans;
    rep(i, C) {
        int a;
        scanf("%d", &a);
        a--;
        if(vis[a]) ans.push_back(i+1);
    }
    printf("%u\n", ans.size());
    rep(i, ans.size()) printf("%d\n", ans[i]);
    return 0;
}


