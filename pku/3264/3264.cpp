#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, q, h[50000], dp[2][16][50000];

int main() {
    scanf("%d%d", &n, &q);
    rep(i, n) scanf("%d", h+i);
    rep(i, n) dp[0][0][i]=h[i];
    rep(i, n) dp[1][0][i]=-h[i];
    rep(d, 2) {
        int r=1;
        rep(k, 15) {
            rep(i, n-2*r+1) dp[d][k+1][i] = min(dp[d][k][i], dp[d][k][i+r]);
            r *= 2;
        }
    }
    rep(i, q) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        int ix=0, r=1;
        while(r*2<b-a) ix++, r*=2;
        int mn = min(dp[0][ix][a], dp[0][ix][b-r]);
        int mx = max(-dp[1][ix][a], -dp[1][ix][b-r]);
        printf("%d\n", mx-mn);
    }
    return 0;
}

