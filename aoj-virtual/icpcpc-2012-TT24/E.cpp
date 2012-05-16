#include <stdio.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1LL<<60)
typedef long long Int;
inline void cmin(Int &a, Int b) { if (a > b) a = b; }

int N, M, L, K[2048], S[200000];
Int sum[200000], dp[2048][2048];

inline Int cost(int a, int b) { return (sum[K[b]+1]-sum[K[a]]) / L; }

int main() {
    scanf("%d%d%d", &N, &M, &L);
    rep (i, N) scanf("%d", K+i);
    rep (i, M) scanf("%d", S+i);
    rep (i, M) sum[i+1] = sum[i] + S[i];
    rep (i, 2048) rep (j, 2048) dp[i][j] = INF;
    rep (i, N) K[i]--;
    sort(K, K+N);
    dp[1][0] = cost(0, 1);
    for (int i = 2; i < N; i++) {
        rep (j, i) {
            cmin(dp[i][i-1], dp[i-1][j] + cost(j, i));
            cmin(dp[i][j], dp[i-1][j] + cost(i-1, i));
        }
    }
    Int ans = INF;
    rep (i, N) cmin(ans, dp[N-1][i] + cost(i, N-1));
    cout << ans << endl;
    return 0;
}
