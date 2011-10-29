#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int n, h[100][128], cnt[256], vis[100][128];
int lo, hi, z;

#define CHECK(x, y) (lo<=h[x][y] && h[x][y]<=hi && vis[x][y]!=z)
bool visit(int x, int y) {
    vis[x][y] = z;
    if(x==n-1 && y==n-1) return true;
    if(x<n-1 && CHECK(x+1, y) && visit(x+1, y)) return true;
    if(y<n-1 && CHECK(x, y+1) && visit(x, y+1)) return true;
    if(x>0 && CHECK(x-1, y) && visit(x-1, y)) return true;
    if(y>0 && CHECK(x, y-1) && visit(x, y-1)) return true;
    return false;
}

bool can(int low, int high) {
    if(h[0][0]<low || h[0][0]>high) return false;
    if(h[n-1][n-1]<low || h[n-1][n-1]>high) return false;
    lo = low, hi = high, z++;
    return visit(0, 0);
}

int solve() {
    memset(cnt, 0, sizeof(cnt));
    int mx = 0;
    rep(i, n) rep(j, n) {
        cnt[h[i][j]]++;
        mx = max(mx, h[i][j]);
    }
    int ans = INF;
    rep(k, mx+1) if(cnt[k]) {
        if(!can(k, mx)) break;
        int l = min(h[0][0], h[n-1][n-1])-1, r = min(mx, k+ans);
        if(!can(k, r)) continue;
        while(r-l>1) {
            const int mid = (l+r)/2;
            if(can(k, mid)) r = mid;
            else l = mid;
        }
        ans = min(ans, r-k);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        scanf(" %d", &n);
        rep(i, n) rep(j, n) scanf(" %d", h[i]+j);
        printf("Scenario #%d:\n", _q+1);
        printf("%d\n", solve());
        printf("\n");
    }
    return 0;
}
