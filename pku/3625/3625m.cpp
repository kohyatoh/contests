#include <stdio.h>
#include <math.h>
#include <set>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
inline double sq(double a) { return a*a; }

int N, M;
int x[1024], y[1024], g[1024][1024], vis[1024];
set<pair<double, int> >::iterator qit[1024];

int main() {
    scanf("%d%d", &N, &M);
    rep(i, N) scanf("%d%d", x+i, y+i);
    rep(i, M) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }
    double ans = 0;
    set<pair<double, int> > q;
    rep(i, N) qit[i] = q.end();
    q.insert(mp(0.0, 0));
    while(!q.empty()) {
        pair<double, int> vv(*q.begin());
        q.erase(q.begin());
        const int cur = vv.second;
        if(vis[cur]) continue;
        vis[cur] = 1;
        ans += sqrt(vv.first);
        rep(i, N) if(!vis[i]) {
            const double di = g[cur][i] ? 0 : sq(x[i]-x[cur])+sq(y[i]-y[cur]);
            if(qit[i]==q.end() || qit[i]->first>di) {
                if(qit[i]!=q.end()) q.erase(qit[i]);
                qit[i] = q.insert(mp(di, i)).first;
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
