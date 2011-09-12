#include <stdio.h>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, x[10000], y[10000];
set<int> sx, sy;

int main() {
    int Q;
    scanf("%d", &Q);
    rep(q, Q) {
        scanf("%d", &n);
        rep(i, n) scanf("%d%d", x+i, y+i);
        rep(i, n) y[i]++;
        sx.clear(), sy.clear();
        sx.insert(1000000000), sy.insert(1000000001);
        int ans=0;
        for(int i=n-1; i>=0; i--) {
            int nx=x[i], ny=y[i];
            set<int>::iterator ixx=sx.upper_bound(x[i]), ixy=sy.lower_bound(x[i]);
            if(*ixx>*ixy) {
                ixx--; nx=*ixx;
                if(*ixx<=y[i] && y[i]<=*ixy) continue;
            }
            set<int>::iterator iyx=sx.upper_bound(y[i]), iyy=sy.lower_bound(y[i]);
            if(*iyx>*iyy) ny=*iyy;
            sx.erase(sx.lower_bound(nx), sx.upper_bound(ny));
            sy.erase(sy.lower_bound(nx), sy.upper_bound(ny));
            sx.insert(nx), sy.insert(ny);
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

