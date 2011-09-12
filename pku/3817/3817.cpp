#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1e100)

inline double sq(double a) { return a*a; }

int n, x[1024], y[1024], p[1024], s[1024];
double dp[1024];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d%d", x+i+1, y+i+1, p+i+1);
        x[0] = y[0] = p[0] = p[n+1] = 0;
        x[n+1] = y[n+1] = 100;
        rep(i, n+2) s[i+1] = s[i]+p[i];
        dp[0] = 0;
        for(int i=1; i<=n+1; i++) {
            dp[i] = INF;
            rep(j, i) {
                const double d = sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
                dp[i] = min(dp[i], dp[j]+d+s[i]-s[j+1]+1);
            }
        }
        printf("%.3f\n", dp[n+1]);
    }
}

