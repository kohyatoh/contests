#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1<<30)
int n, b, u[4000], dp[2][4000][2];

int main() {
    scanf("%d%d", &n, &b);
    rep(i, n) scanf("%d", u+i);
    int ans=-INF;
    rep(fs, 2) {
        int (*cur)[2]=dp[0], (*nxt)[2]=dp[1];
        rep(i, b+1) cur[i][0]=cur[i][1]=-INF;
        cur[0][fs] = 0;
        rep(i, n) {
            rep(j, b+1) nxt[j][0]=nxt[j][1]=-INF;
            rep(j, b+1) {
                nxt[j][0] = max(nxt[j][0], cur[j][0]);
                nxt[j+1][1] = max(nxt[j+1][1], cur[j][0]);
                nxt[j][0] = max(nxt[j][0], cur[j][1]);
                nxt[j+1][1] = max(nxt[j+1][1], cur[j][1]+u[i]);
            }
            swap(cur, nxt);
        }
        ans = max(ans, cur[b][fs]);
    }
    printf("%d\n", ans);
    return 0;
}

