#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF (1<<28)

int n, m, dp[1024][1024];
char f[1024], g[1024];

int rec(int x, int y) {
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==n) return m-y;
    if(y==m) return n-x;
    int ans = rec(x+1, y+1)+(f[x]!=g[y]);
    ans = min(ans, rec(x+1, y)+1);
    ans = min(ans, rec(x, y+1)+1);
    return dp[x][y] = ans;
}

int main() {
    while(scanf(" %d%s%d%s", &n, f, &m, g)!=EOF) {
        memset(dp, -1, sizeof(dp));
        printf("%d\n", rec(0, 0));
    }
    return 0;
}
