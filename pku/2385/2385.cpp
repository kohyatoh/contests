#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
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
#include <functional>
#include <complex>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#define DBG(...) (fprintf(stderr,"%d: ",__LINE__)+fprintf(stderr,__VA_ARGS__))
#else
#define LOG(...) ((void)0)
#define ASS(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<30)

int n, w, dp[50][2];

int main() {
    scanf("%d%d", &n, &w);
    rep(i, 50) rep(j, 2) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(k, n) {
        int a;
        scanf("%d", &a);
        a--;
        for(int i=w; i>=0; i--) rep(j, 2) {
            dp[i][j] = max(dp[i][j], dp[i][j]+(a==j));
            dp[i+1][1-j] = max(dp[i+1][1-j], dp[i][j]+(a!=j));
        }
    }
    int ans = 0;
    rep(i, w+1) rep(j, 2) ans=max(ans, dp[i][j]);
    printf("%d\n", ans);
    return 0;
}


