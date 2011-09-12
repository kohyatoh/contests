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
#define INF MY_INFINITY

int n, m, vis[100];
double g[100][100];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d", &m);
        memset(g, 0, sizeof(g));
        rep(i, m) {
            int a, b, p;
            scanf("%d%d%d", &a, &b, &p);
            a--, b--;
            g[a][b] = g[b][a] = p/100.0;
        }
        memset(vis, 0, sizeof(vis));
        priority_queue<pair<double, int> > q;
        q.push(mp(1.0, 0));
        while(!q.empty()) {
            pair<double, int> v(q.top());
            q.pop();
            if(vis[v.second]) continue;
            vis[v.second] = 1;
            if(v.second==n-1) {
                printf("%.6f percent\n", v.first*100);
                break;
            }
            rep(i, n) q.push(mp(v.first*g[v.second][i], i));
        }
    }
}


