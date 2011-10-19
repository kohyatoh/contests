#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int K, N, M;
vector<int> vs[100], ls[100], ts[100];

int solve() {
    priority_queue<pair<int, pair<int, int> > > q;
    set<pair<int, int> > vis;
    q.push(mp(0, mp(0, 0)));
    while(!q.empty()) {
        pair<int, pair<int, int> > vv(q.top());
        q.pop();
        if(vis.count(vv.second)) continue;
        vis.insert(vv.second);
        const int u = vv.second.first;
        const int ct = vv.second.second;
        const int cd = -vv.first;
        if(u==N-1) return cd;
        rep(i, vs[u].size()) if(ct+ts[u][i]<=K) {
            q.push(mp(-cd-ls[u][i], mp(vs[u][i], ct+ts[u][i])));
        }
    }
    return -1;
}

int main() {
    scanf("%d%d%d", &K, &N, &M);
    rep(_, M) {
        int u, v, l, t;
        scanf("%d%d%d%d", &u, &v, &l, &t);
        u--, v--;
        vs[u].push_back(v);
        ls[u].push_back(l);
        ts[u].push_back(t);
    }
    printf("%d\n", solve());
    return 0;
}
