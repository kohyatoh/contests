#include <stdio.h>
#include <numeric>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct coin { int a, c, d; };
bool operator<(const coin& l, const coin& r) {
    return l.d!=r.d?l.d<r.d:l.a<r.a;
}

int n, m;
coin coins[200];
int dp[100010], dc[100010];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) scanf("%d", &coins[i].a);
        rep(i, n) scanf("%d", &coins[i].c);
        rep(i, n) coins[i].d=coins[i].a*coins[i].c;
        sort(coins, coins+n);
        rep(i, m+1) dp[i]=0;
        dp[0]=1;
        int ans=0, mm=0;
        int a, c, lim, col;
        rep(i, n) {
            a=coins[i].a, c=coins[i].c, col=i+2;
            mm += a*c;
            lim=min(m-a, mm)+1;
            rep(k, lim) if(dp[k] && !dp[k+a]) {
                if(dp[k]<col) {
                    ans++;
                    dp[k+a] = col;
                    dc[k+a] = 1;
                }
                else if(dc[k]<c) {
                    ans++;
                    dp[k+a] = col;
                    dc[k+a] = dc[k]+1;
                }
            }
        }
        printf("%d\n", ans);
    }
}
