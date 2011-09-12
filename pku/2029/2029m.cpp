#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, w, h, s, t, f[100][100], dp1[100][100], dp2[100][100];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d%d", &w, &h);
        rep(i, w) rep(j, h) f[i][j]=0;
        rep(i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            f[x-1][y-1]++;
        }
        scanf("%d%d", &s, &t);
        rep(i, w) rep(j, h) {
            dp1[i][j] = f[i][j];
            if(j>0) dp1[i][j] += dp1[i][j-1];
            if(j>=t) dp1[i][j] -= f[i][j-t];
        }
        rep(i, w) rep(j, h) {
            dp2[i][j] = dp1[i][j];
            if(i>0) dp2[i][j] += dp2[i-1][j];
            if(i>=s) dp2[i][j] -= dp1[i-s][j];
        }
        int ans=-1;
        rep(i, w) rep(j, h) ans=max(ans, dp2[i][j]);
        printf("%d\n", ans);
    }
}
