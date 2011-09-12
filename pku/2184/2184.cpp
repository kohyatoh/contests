#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define M (262144)
int n, s, f, dp[M], tmp[M];

int main() {
    scanf("%d", &n);
    rep(i, M) dp[i]=tmp[i]=-M;
    dp[M/2]=tmp[M/2]=0;
    int l=M/2, u=M/2;
    rep(i, n) {
        scanf("%d%d", &s, &f);
        for(int i=l; i<=u; i++) tmp[i+f]=max(tmp[i+f], dp[i]+s);
        l = min(l, l+f);
        u = max(u, u+f);
        for(int i=l; i<=u; i++) dp[i]=tmp[i];
    }
    int ans=0;
    for(int i=M/2+1; i<=u; i++) if(dp[i]>0) ans=max(ans, i-M/2+dp[i]);
    printf("%d\n", ans);
    return 0;
}
