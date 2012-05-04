#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (1000000007LL)

int n, a[64], w[64][64];
int dp[52][52][52][52];

inline int f(int h, int k, int l, int r) {
    return l > r ? 0 : dp[h][k][l][r];
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i);
    rep (i, n) rep (j, n-i) scanf("%d", w[i]+j);
    rep (i, n) if (a[i] >= w[0][i]) dp[0][i][i][i] = a[i];
    for (int h = 1; h < n; h++) rep (k, n-h) {
        for (int l = k; l <= k+h; l++) for (int r = l; r <= k+h; r++) {
            for (int z = l-1; z <= r; z++) {
                dp[h][k][l][r] = max(dp[h][k][l][r],
                        f(h-1, k, l, z) + f(h-1, k+1, z+1, r));
            }
            if (dp[h][k][l][r] < w[h][k]) dp[h][k][l][r] = 0;
        }
    }
    puts(dp[n-1][0][0][n-1] < w[n-1][0] ? "Fat Rat" : "Cerealguy");
    return 0;
}
