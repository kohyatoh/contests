#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

int W, L;

int m, n, a[128];
double dp[128][128][128];

int main() {
    rep (i, 6) rep (j, 6) if (i < j) W++; else L++;
//    printf("%d %d\n", W, L);
    int T;
    scanf("%d", &T);
    rep (_, T) {
        scanf("%d%d", &m, &n);
        rep (i, n) scanf("%d", a+i);
        memset(dp, 0, sizeof(dp));
        for (int k = n-1; k >= 0; k--) {
            rep (j, m+1) {
                if (k+1 < n) dp[k][0][j] = dp[k+1][a[k+1]][j];
                else dp[k][0][j] = j;
            }
            rep (i, a[k]+1) if (i) {
                rep (j, m+1) if (j) {
                    dp[k][i][j] += W/36.0 * dp[k][i-1][j];
                    dp[k][i][j] += L/36.0 * dp[k][i][j-1];
                }
            }
        }
        printf("%.9f\n", dp[0][a[0]][m]);
    }
    return 0;
}
