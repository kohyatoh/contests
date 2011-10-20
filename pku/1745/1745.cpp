#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

inline int mod(int a, int m) { return (a>=0 ? a : m-(-a%m)) % m; }

int n, m, a[20000], cnt[128], dp[2][128];

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) scanf("%d", a+i);
    for(int i=1; i<n; i++) cnt[mod(a[i], m)]++;
    int *cur=dp[0], *nxt=dp[1];
    cur[mod(a[0], m)] = 1;
    rep(x, m) if(cnt[x]) {
        memset(nxt, 0, sizeof(dp[0]));
        rep(k, cnt[x]+1) {
            const int z = mod(x*(2*k-cnt[x]), m);
            rep(i, m-z) if(cur[i]) nxt[i+z] = 1;
            for(int i=m-z; i<m; i++) if(cur[i]) nxt[i+z-m] = 1;
        }
        swap(cur, nxt);
    }
    puts(cur[0] ? "Divisible" : "Not divisible");
    return 0;
}
