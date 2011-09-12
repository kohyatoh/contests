#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, k, dp[1000], pre[1000];
vector<int> g[1000];

void pr(int i) {
    if(pre[i]!=-1) pr(pre[i]);
    printf("%d\n", i+1);
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i, n) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a-1].push_back(b-1);
    }
    priority_queue<pair<int, pair<int, int> > > q;
    q.push(mp(-1, mp(0, -1)));
    memset(dp, -1, sizeof(dp));
    while(!q.empty()) {
        pair<int, pair<int, int> > v=q.top();
        q.pop();
        int cur=v.second.first;
        if(dp[cur]!=-1) continue;
        dp[cur] = -v.first;
        pre[cur] = v.second.second;
        if(cur==k-1) break;
        rep(i, g[cur].size()) if(dp[g[cur][i]]==-1) {
            q.push(mp(v.first-1, mp(g[cur][i], cur)));
        }
    }
    printf("%d\n", dp[k-1]);
    if(dp[k-1]!=-1) pr(k-1);
    return 0;
}

