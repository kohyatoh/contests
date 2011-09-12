#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int n, x[6000], y[6000], dp[1020000];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, n) scanf("%d%d", x+i, y+i);
        rep(i, 1020000) dp[i] = INF;
        dp[x[0]] = 0;
        rep(k, n) {
            const double L = sqrt(y[0]*(2.*y[k]-y[0]));
            for(int i=min((int)L, x[k]-x[0]); i>0; i--) {
                const int to = min(x[k]+i, x[n-1]);
                dp[to] = min(dp[to], dp[x[k]-i]+1);
            }
        }
        printf("%d\n", dp[x[n-1]]<INF ? dp[x[n-1]] : -1);
    }
    return 0;
}
