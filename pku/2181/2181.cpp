#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, dp[2][2];

int main() {
    scanf("%d", &n);
    int *cur=dp[0], *nxt=dp[1];
    cur[0]=0, cur[1]=-(1<<30);
    int ans=0;
    rep(i, n) {
        int p;
        scanf("%d", &p);
        nxt[0] = max(cur[0], cur[1]-p);
        nxt[1] = max(cur[1], cur[0]+p);
        ans = max(ans, nxt[0]);
        ans = max(ans, nxt[1]);
        swap(cur, nxt);
    }
    printf("%d\n", ans);
    return 0;
}
