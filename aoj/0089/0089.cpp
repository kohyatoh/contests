#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define INF (1<<28)

int n, f[128][128], dp[128][128];

int main() {
    rep (i, 128) rep (j, 128) f[i][j] = -INF;
    string s;
    while (getline(cin, s)) {
        rep (i, s.size()) if (s[i] == ',') s[i] = ' ';
        int k = 0;
        istringstream sin(s);
        string w;
        while (sin >> w) f[n][k++] = atoi(w.c_str());
        n++;
    }
    rep (i, 128) rep (j, 128) dp[i][j] = -INF;
    dp[0][0] = f[0][0];
    for (int i = 1; i <= n/2; i++) {
        rep (j, 128) {
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+f[i][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]+f[i][j]);
        }
    }
    for (int i = n/2+1; i < n; i++) {
        rep (j, 128) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]+f[i][j]);
            if (j < 127) dp[i][j] = max(dp[i][j], dp[i-1][j+1]+f[i][j]);
        }
    }
    printf("%d\n", dp[n-1][0]);
    return 0;
}
