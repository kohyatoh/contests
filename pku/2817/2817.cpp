#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmax(int &a, int b) { if(a<b) a = b; }

int n, f[16][16], dp[65536][16];
string s[16];

int main() {
    char buf[16];
    for(;;) {
        scanf("%d", &n);
        if(n<=0) return 0;
        rep(i, n) {
            scanf("%s", buf);
            s[i] = buf;
        }
        rep(i, n) rep(j, n) {
            f[i][j] = 0;
            rep(k, s[i].size()) {
                const int r = min(s[i].size()-k, s[j].size());
                int a = 0;
                rep(x, r) if(s[i][k+x]==s[j][x]) a++;
                cmax(f[i][j], a);
            }
        }
        const int nn = 1<<n;
        rep(i, nn) rep(j, n) dp[i][j] = -INF;
        rep(i, n) dp[1<<i][i] = 0;
        rep(b, nn) rep(k, n) if(dp[b][k]>=0) {
            rep(i, n) if((b&(1<<i))==0) {
                cmax(dp[b|(1<<i)][i], dp[b][k]+max(f[i][k], f[k][i]));
            }
        }
        int ans = 0;
        rep(i, n) ans = max(ans, dp[nn-1][i]);
        printf("%d\n", ans);
    }
}
