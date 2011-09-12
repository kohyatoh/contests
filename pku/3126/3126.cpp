#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int pt[10000], n, v[1100], vis[1100];
vector<int> g[1100];

int main() {
    for(int i=2; i<10000; i++) if(pt[i]==0) {
        if(i>1000) v[n++] = i;
        for(int j=i*i; j<10000; j+=i) pt[j] = i;
    }
    rep(i, n) rep(j, n) {
        int t=1, c=0;
        rep(_, 4) {
            c += v[i]/t%10 != v[j]/t%10;
            t *= 10;
        }
        if(c==1) g[i].push_back(j);
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        int st, gl;
        scanf("%d%d", &st, &gl);
        const int six = lower_bound(v, v+n, st)-v;
        const int gix = lower_bound(v, v+n, gl)-v;
        queue<pair<int, int> > q;
        q.push(mp(0, six));
        rep(i, n) vis[i] = 0;
        while(!q.empty()) {
            pair<int, int> cv(q.front());
            q.pop();
            int cur = cv.second;
            if(vis[cur]) continue;
            vis[cur] = 1;
            if(cur==gix) {
                printf("%d\n", cv.first);
                goto found;
            }
            rep(i, g[cur].size()) q.push(mp(cv.first+1, g[cur][i]));
        }
        puts("Impossible");
found:;
    }
    return 0;
}

