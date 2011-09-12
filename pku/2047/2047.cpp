#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct app { int s, e, w; };
bool operator<(const app& l, const app& r) { return l.e<r.e; }

int n, m, dp[400][400];
app a[1000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d%d", &a[i].s, &a[i].e, &a[i].w);
        sort(a, a+n);
        memset(dp, 0, sizeof(dp));
        rep(k, n) {
            for(int i=365; i>=0; i--) {
                dp[i][a[k].e]=max(dp[i][a[k].e], dp[i][a[k].s-1]+a[k].w);
                dp[a[k].e][i]=max(dp[a[k].e][i], dp[a[k].s-1][i]+a[k].w);
            }
            int u = k+1<n ? a[k+1].e : 365;
            for(int i=a[k].e; i<u; i++) {
                rep(j, u+1) {
                    dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
                    dp[j][i+1]=max(dp[j][i+1], dp[j][i]);
                }
            }
        }
        printf("%d\n", dp[365][365]);
    }
}
