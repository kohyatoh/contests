#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (1<<28)

struct UnionSet {
    int ud[1024];
    void init(int n) { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int N, P, K, u[10000], v[10000], w[10000];
int ct[1024], vs[1024][1024];
int dp[1024], col[1024][1024], z;

bool ok(int m) {
    us.init(N);
    memset(ct, 0, sizeof(ct));
    z++;
    rep(i, P) if(w[i]<=m) us.set(u[i], v[i]);
    rep(i, P) if(w[i]>m) {
        const int x = us.root(u[i]), y = us.root(v[i]);
        if(x==y || col[x][y]==z) continue;
        col[x][y] = col[y][x] = z;
        vs[x][ct[x]++] = y;
        vs[y][ct[y]++] = x;
    }
    const int st = us.root(0), gl = us.root(N-1);
    if(st==gl) return true;
    memset(dp, -1, sizeof(dp));
    queue<int> q;
    q.push(st);
    dp[st] = 0;
    while(!q.empty()) {
        const int at = q.front();
        q.pop();
        if(dp[at]<K) rep(i, ct[at]) if(dp[vs[at][i]]==-1) {
            if(vs[at][i]==gl) return true;
            q.push(vs[at][i]);
            dp[vs[at][i]] = dp[at]+1;
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &N, &P, &K);
    int L = 0;
    rep(i, P) {
        scanf("%d%d%d", u+i, v+i, w+i);
        u[i]--, v[i]--;
        L = max(L, w[i]);
    }
    int l = -1, r = L+1;
    while(r-l>1) {
        const int mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n", r<=L ? r : -1);
    return 0;
}
