#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (1<<28)
void cmax(int &a, int b) { if(a<b) a = b; }

int n, m, a[4000];
vector<int> g[4000], w[4000];
int cnt[4000];
vector<int> dp[4000];

void rec(int at) {
    if(at>=n-m) {
        cnt[at] = 1;
        dp[at].push_back(0);
        dp[at].push_back(a[at-(n-m)]);
        return ;
    }

    vector<pair<int, int> > xs;
    rep(k, g[at].size()) {
        const int v = g[at][k];
        rec(v);
        xs.push_back(mp(cnt[v], k));
    }
    sort(xs.begin(), xs.end());

    dp[at].push_back(0);
    rep(q, xs.size()) {
        const int k = xs[q].second;
        const int v = g[at][k], cw = w[at][k];
        const int c = cnt[v];
        dp[at].resize(cnt[at]+1+c);
        rep(i, c) dp[at][cnt[at]+1+i] = -INF;
        for(int i=cnt[at]; i>=0; i--) for(int j=1; j<=c; j++) {
            cmax(dp[at][i+j], dp[at][i]+dp[v][j]-cw);
        }
        cnt[at] += c;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n-m) {
        int c, v, _w;
        scanf(" %d", &c);
        while(c--) {
            scanf("%d%d", &v, &_w);
            v--;
            g[i].push_back(v);
            w[i].push_back(_w);
        }
    }
    rep(i, m) scanf("%d", a+i);
    rec(0);
    int ans = 0;
    rep(i, cnt[0]+1) if(dp[0][i]>=0) ans = i;
    printf("%d\n", ans);
    return 0;
}
