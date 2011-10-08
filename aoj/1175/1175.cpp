#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline double sq(double a) { return a*a; }

int bitcount(int b) { int c = 0; while(b) { b &= b-1; c++; } return c; }

int n, x[64], y[64], r[64], c[64], g[64];
bool vis[1<<24];

int solve() {
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    rep(i, n) for(int j=i+1; j<n; j++) {
        if(sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]))<r[i]+r[j]) g[i] |= 1<<j;
    }
    vector<int> cs[4];
    rep(i, n) cs[c[i]-1].push_back(i);
    int ans = 0;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans = max(ans, bitcount(x));
        int can = ~x;
        rep(i, n) if((x&(1<<i))==0) can &= ~g[i];
        rep(k, 4) rep(i, cs[k].size()) if(can&(1<<cs[k][i])) {
            rep(j, i) if(can&(1<<cs[k][j])) {
                const int nx = x|(1<<cs[k][i])|(1<<cs[k][j]);
                if(!vis[nx]) q.push(nx), vis[nx] = true;
            }
        }
    }
    return ans;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d%d%d", x+i, y+i, r+i, c+i);
        printf("%d\n", solve());
    }
}
