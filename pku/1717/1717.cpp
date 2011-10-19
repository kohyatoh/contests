#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
#define mp make_pair

#define B (15000)
int n, a[2000], b[2000], dp[2][30000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", a+i, b+i);
    map<int, int> cnt;
    rep(i, n) cnt[2*(b[i]-a[i])]++;
    vector<pair<int, int> > xs;
    for(map<int, int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) {
        int r = it->second;
        for(int k=1; k<r; k*=2) {
            xs.push_back(mp(k, k*it->first));
            r -= k;
        }
        xs.push_back(mp(r, r*it->first));
    }
    int *cur=dp[0], *nxt=dp[1];
    rep(i, 30000) cur[i] = INF;
    cur[B] = 0;
    rep(k, xs.size()) {
        rep(i, 30000) nxt[i] = cur[i];
        rep(i, 30000) if(cur[i]<INF) {
            nxt[i+xs[k].second] = min(nxt[i+xs[k].second], cur[i]+xs[k].first);
        }
        swap(cur, nxt);
    }
    int s = 0;
    rep(i, n) s += a[i]-b[i];
    pair<int, int> ans(INF, -1);
    rep(i, 30000) if(cur[i]<INF) ans = min(ans, mp(abs(s+i-B), cur[i]));
    printf("%d\n", ans.second);
    return 0;
}
