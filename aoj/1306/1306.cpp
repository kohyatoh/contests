#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int n, p[100], t[100], dp[100][4];

void solve() {
    rep(i, 100) rep(j, 4) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, n-1) rep(j, 4) {
        const int dt = t[i+1]-t[i];
        if((j+1)*p[i]+p[i+1]<=dt) {
            dp[i+1][1] = min(dp[i+1][1], dp[i][j]+p[i]+p[i+1]);
        }
        if(j<3 && (j+1)*abs(p[i]-p[i+1])<=dt) {
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+abs(p[i]-p[i+1]));
        }
    }
    rep(i, n) {
        bool ok = false;
        rep(j, 4) if(dp[i][j]<INF) ok = true;
        if(!ok) {
            printf("NG %d\n", i);
            return ;
        }
    }
    int ans = INF;
    rep(j, 4) ans = min(ans, dp[n-1][j]+p[n-1]);
    printf("OK %d\n", ans);
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        p[0] = t[0] = 0;
        rep(i, n) scanf("%d%d", p+i+1, t+i+1);
        n++;
        solve();
    }
}

