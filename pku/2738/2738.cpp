#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmax(int &a, int b) { if(a<b) a = b; }

int a[1024], dp[1024][1024];

int main() {
    for(int _q=0;; _q++) {
        int n;
        scanf(" %d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        for(int w=2; w<=n; w++) rep(i, n-w+1) {
            const int j = i+w-1;
            dp[i][j] = -INF;
            if(a[i+1]>=a[j]) cmax(dp[i][j], dp[i+2][j]+a[i]-a[i+1]);
            else cmax(dp[i][j], dp[i+1][j-1]+a[i]-a[j]);
            if(a[i]>=a[j-1]) cmax(dp[i][j], dp[i+1][j-1]+a[j]-a[i]);
            else cmax(dp[i][j], dp[i][j-2]+a[j]-a[j-1]);
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", _q+1, dp[0][n-1]);
    }
}
