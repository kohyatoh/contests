#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

unsigned dp[2][1<<12];

int main() {
    int T;
    scanf("%d", &T);
    rep(_t, T) {
        int n;
        scanf("%d", &n);
        const int nn = 1<<n;
        unsigned ans = 0;
        memset(dp, 0, sizeof(dp));
        unsigned *cur=dp[0], *nxt=dp[1];
        cur[0] = 1;
        rep(i, n) {
            memset(nxt, 0, sizeof(dp[0]));
            rep(b, nn) {
                const int z = (nn-1)^b;
                for(int x=z; x; x=(x-1)&z) nxt[b|x] += cur[b];
            }
            swap(cur, nxt);
            rep(b, nn) ans+=cur[b];
        }
        printf("%d %d %u\n", _t+1, n, ans);
    }
    return 0;
}
