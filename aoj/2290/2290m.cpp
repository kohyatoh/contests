#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (1LL<<60)
typedef long long Int;

struct node { int x, t, p; };
bool operator<(const node& l, const node& r) {
    return l.t!=r.t ? l.t<r.t : l.x!=r.x ? l.x<r.x : l.p<r.p;
}

int N, V, XL, XR;
node X[4000];

inline bool connect(int i, int j) {
    return abs(X[j].x-X[i].x)<=(long long)V*abs(X[j].t-X[i].t);
}

pair<int, int> pre[6400];
int vis[6400];
Int h[6400];
vector<int> v[6400];
vector<Int> c[6400];
set<pair<Int, int> >::iterator z[6400];
bool has[6400];


inline void add_edge(int _u, int _v, Int _c) {
    v[_u].push_back(_v);
    c[_u].push_back(_c);
}

int main() {
    scanf("%d%d%d%d", &N, &V, &XL, &XR);
    X[0].x = XL;
    X[1].x = XR;
    rep(i, N) scanf("%d%d%d", &X[i+2].x, &X[i+2].t, &X[i+2].p);
    N += 2;
    sort(X, X+N);

    rep(i, 2+N*2) h[i] = INF;
    h[0] = 0;
    rep(i, 2) add_edge(0, 2+i*2, 0), h[2+i*2] = 0, pre[2+i*2] = mp(0, i);
    rep(i, N) {
        const int f = 2+2*i+1;
        add_edge(f-1, f, -X[i].p), h[f] = h[f-1]-X[i].p, pre[f] = mp(f-1, 0);
        add_edge(f, 1, 0);
        if(h[1]>h[f]) h[1] = h[f], pre[1] = mp(f, 0);
        for(int j=i+1; j<N; j++) if(connect(i, j)) {
            const int t = 2+2*j;
            add_edge(f, t, 0);
            if(h[t]>h[f]) h[t] = h[f], pre[t] = mp(f, v[f].size()-1);
        }
    }

    int cur = 1;
    while(cur!=0) {
        const int f = pre[cur].first;
        const int k = pre[cur].second;
        add_edge(cur, f, -c[f][k]);
        c[f][k] = INF;
        cur = f;
    }

    set<pair<Int, int> > q;
    q.insert(mp(0, 0));
    while(!q.empty()) {
        const pair<Int, int> vv(*q.begin());
        q.erase(q.begin());
        const int cc = vv.first;
        const int ix = vv.second;
        if(vis[ix]) continue;
        vis[ix] = 1;
        if(ix==1) {
            cout << -(h[1]*2+cc) << endl;
            break;
        }
        rep(i, v[ix].size()) if(!vis[v[ix][i]]) {
            const Int nc = cc + c[ix][i] + h[ix] - h[v[ix][i]];
            if(has[v[ix][i]]) {
                if(z[v[ix][i]]->first <= nc) continue;
                q.erase(z[v[ix][i]]);
            }
            has[v[ix][i]] = true;
            z[v[ix][i]] = q.insert(mp(nc, v[ix][i])).first;
        }
    }
    return 0;
}
