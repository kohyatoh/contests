#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1LL<<60)
typedef long long Int;
inline void update(Int &a, Int b) { if(a>b) a=b; }

int N, M, L, K[2048], S[200000];
Int sum[200000], dp[2048][2048];

inline Int f(int l, int r) { return (sum[K[r]+1]-sum[K[l]])/L; }

int main() {
    scanf("%d%d%d", &N, &M, &L);
    rep(i, N) scanf("%d", K+i);
    rep(i, N) K[i]--;
    rep(i, M) scanf("%d", S+i);
    rep(i, M) sum[i+1] = sum[i] + S[i];
    sort(K, K+N);
    rep(i, 2048) rep(j, 2048) dp[i][j] = INF;
    dp[0][1] = f(0, 1);
    for(int k=1; k<N-1; k++) rep(i, k) {
        update(dp[i][k+1], dp[i][k]+f(k, k+1));
        update(dp[k][k+1], dp[i][k]+f(i, k+1));
    }
    Int ans = INF;
    rep(i, N-1) update(ans, dp[i][N-1]+f(i, N-1));
    cout << ans << endl;
    return 0;
}

