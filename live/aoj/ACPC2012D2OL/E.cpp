#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (100000007LL)
typedef long long Int;
inline void add(Int &a, Int b) { a = (a + b) % MOD; }

int n, m;
char f[16][16];
Int dp[120][177147];

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) rep (j, m) scanf(" %c", f[i]+j);
    dp[0][0] = 1;
    int mm = 1;
    rep (_, m) mm *= 3;
    rep (k, n*m) rep (b, mm*3) if (dp[k][b]) {
        const int t1 = b / mm, t2 = b % 3;
        const int nb = (b-t1*mm-t2)*3;
        if (k % m == 0 && t2) continue;
        if (f[k/m][k%m] == '.') {
            if (t1 && t2) continue;
            add(dp[k+1][nb+t1*3+t2], dp[k][b]);
        }
        else {
            const int z = f[k/m][k%m] - '0';
            rep (t3, 3) {
                const int t4 = z - t1 - t2 - t3;
                if (t4 < 0 || t4 > 2) continue;
                add(dp[k+1][nb+t3*3+t4], dp[k][b]);
            }
        }
    }
    printf("%d\n", (int)dp[n*m][0]);
    return 0;
}
