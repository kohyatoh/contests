#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int N, E, T, W[500], G[2000], C[2000], S[2000][16], dp[500];

int main() {
    scanf("%d%d%d", &N, &E, &T);
    T--;
    rep(i, N) scanf("%d", W+i);
    rep(i, E) {
        scanf("%d%d", G+i, C+i);
        G[i]--;
        rep(j, C[i]) scanf("%d", S[i]+j);
        rep(j, C[i]) S[i][j]--;
    }
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, int> > q;
    rep(i, N) if(W[i]) q.push(mp(-1, i));
    while(!q.empty() && dp[T]==-1) {
        pair<int, int> vx(q.top());
        q.pop();
        const int ix = vx.second;
        if(dp[ix]!=-1) continue;
        dp[ix] = -vx.first;
        rep(i, E) if(dp[G[i]]==-1) {
            bool can = true;
            rep(j, C[i]) if(dp[S[i][j]]==-1) can = false;
            if(can) {
                vector<int> v;
                rep(j, C[i]) v.push_back(dp[S[i][j]]);
                sort(v.begin(), v.end(), greater<int>());
                int mx = 0;
                rep(j, v.size()) mx = max(mx, v[j]+j);
                q.push(mp(-mx, G[i]));
            }
        }
    }
    printf("%d\n", dp[T]);
    return 0;
}
