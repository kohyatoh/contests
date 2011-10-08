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
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

const double pi = atan2(0.0, -1.0);

int N, L[2000];
double dp[1024][1024];

void solve() {
    scanf("%d", &N);
    rep(i, N) scanf("%d", L+i);
    sort(L, L+N);
    rep(i, 1024) rep(j, 1024) dp[i][j] = -1e100;
    const double s = sin(2*pi/N)/2;
    dp[0][1] = L[0]*L[1]*s;
    for(int i=1; i<N-1; i++) {
        rep(j, i) dp[j][i+1] = max(dp[j][i+1], dp[j][i]+L[i]*L[i+1]*s);
        rep(j, i) dp[i][i+1] = max(dp[i][i+1], dp[j][i]+L[j]*L[i+1]*s);
    }
    double ans = 0;
    rep(i, N-1) ans = max(ans, dp[i][N-1]+L[i]*L[N-1]*s);
    printf("%.9f\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    rep(t, T) {
        printf("Case #%d: ", t+1);
        solve();
    }
    return 0;
}



