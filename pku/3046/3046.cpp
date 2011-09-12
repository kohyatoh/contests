#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define MOD (1000000)

int cnt[1000], dp[200000], s[200000];

int main() {
    int T, A, S, B;
    scanf("%d%d%d%d", &T, &A, &S, &B);
    rep(_, A) {
        int t;
        scanf("%d", &t);
        cnt[t-1]++;
    }
    dp[200] = 1;
    int m = 201;
    rep(k, T) {
        m += cnt[k];
        rep(i, m) s[i+1] = (s[i]+dp[i])%MOD;
        for(int i=200; i<m; i++) {
            dp[i] = (s[i+1]-s[i-cnt[k]]+MOD)%MOD;
        }
    }
    int ans = 0;
    for(int i=S; i<=B; i++) ans = (ans+dp[i+200])%MOD;
    printf("%d\n", ans);
    return 0;
}
