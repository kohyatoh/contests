#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (100000007LL)
typedef long long Int;

Int C[1024][1024];

int main() {
    C[0][0] = 1;
    rep (i, 1024-1) rep (j, 1024-1) {
        C[i+1][j] = (C[i+1][j] + C[i][j]) % MOD;
        C[i+1][j+1] = (C[i+1][j+1] + C[i][j]) % MOD;
    }
    int r, c, a1, a2, b1, b2;
    scanf("%d%d%d%d%d%d", &r, &c, &a1, &a2, &b1, &b2);
    const int dx1 = (a1-b1+r)%r, dx2 = (b1-a1+r)%r;
    const int dy1 = (a2-b2+c)%c, dy2 = (b2-a2+c)%c;
    const int dx = min(dx1, dx2), dy = min(dy1, dy2);
    Int ans = C[dx+dy][dx];
    if (dx && dx1 == dx2) ans = (ans * 2) % MOD;
    if (dy && dy1 == dy2) ans = (ans * 2) % MOD;
    cout << ans << endl;
    return 0;
}
