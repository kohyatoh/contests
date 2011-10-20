#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (64)

int f[4][4], g[4][4];

void flip(int i, int j) {
    g[i][j] ^= 1;
    if(i>0) g[i-1][j] ^= 1;
    if(j>0) g[i][j-1] ^= 1;
    if(i<3) g[i+1][j] ^= 1;
    if(j<3) g[i][j+1] ^= 1;
}

int solve(int c) {
    int ans = INF;
    rep(b, 1<<4) {
        rep(i, 4) rep(j, 4) g[i][j] = f[i][j];
        int a = 0;
        rep(i, 4) if(b&(1<<i)) flip(0, i), a++;
        rep(i, 3) rep(j, 4) if(g[i][j]!=c) flip(i+1, j), a++;
        rep(i, 4) if(g[3][i]!=c) a = INF;
        ans = min(ans, a);
    }
    return ans;
}

int main() {
    rep(i, 4) rep(j, 4) {
        char ch;
        scanf(" %c", &ch);
        f[i][j] = ch=='b';
    }
    const int ans = min(solve(0), solve(1));
    if(ans<INF) printf("%d\n", ans);
    else puts("Impossible");
    return 0;
}
