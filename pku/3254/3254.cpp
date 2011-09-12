#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define MOD (100000000)

int n, m, f[20], dp[20][1<<12];
int k, v[1<<12];

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) {
        int a;
        scanf("%d", &a);
        f[i] |= (1-a)<<j;
    }
    const int mm = 1<<m;
    rep(b, mm) {
        bool ok = true;
        rep(i, m) if((b&(3<<i))==(3<<i)) ok = false;
        if(ok) v[k++] = b;
    }
    dp[0][0] = 1;
    rep(i, n) rep(j, k) rep(x, k) if(((f[i]|v[j])&v[x])==0) {
        dp[i+1][v[x]] = (dp[i+1][v[x]]+dp[i][v[j]])%MOD;
    }
    int ans = 0;
    rep(i, k) ans = (ans+dp[n][v[i]])%MOD;
    printf("%d\n", ans);
    return 0;
}
