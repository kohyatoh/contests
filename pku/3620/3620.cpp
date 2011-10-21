#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

int N, M, f[128][128];

int rec(int x, int y) {
    if(f[x][y]==0) return 0;
    f[x][y] = 0;
    int c = 1;
    c += rec(x+1, y);
    c += rec(x-1, y);
    c += rec(x, y+1);
    c += rec(x, y-1);
    return c;
}

int main() {
    int K;
    scanf("%d%d%d", &N, &M, &K);
    rep(i, K) {
        int x, y;
        scanf("%d%d", &x, &y);
        f[x][y] = 1;
    }
    int ans = 0;
    rep(i, N) rep(j, M) if(f[i+1][j+1]) ans = max(ans, rec(i+1, j+1));
    printf("%d\n", ans);
    return 0;
}
