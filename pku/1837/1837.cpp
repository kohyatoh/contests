#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

#define B (1<<13)
int C, G, w[32], a[32];
Int dp[32][1<<14];

int main() {
    scanf("%d%d", &C, &G);
    rep(i, C) scanf("%d", w+i);
    rep(i, G) scanf("%d", a+i);
    dp[0][B] = 1;
    rep(k, G) rep(i, 1<<14) if(dp[k][i]) {
        rep(j, C) dp[k+1][i+w[j]*a[k]] += dp[k][i];
    }
    cout << dp[G][B] << endl;
    return 0;
}
