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
#define MOD (YOUR_MODULUS)

int n;
string ss[600000];
char buf[16];
int dp[32][32], old[32];

int main() {
    scanf("%d", &n);
    rep (i, n) {
        scanf("%s", buf);
        ss[i] = buf;
    }
    memset(dp, -1, sizeof(dp));
    rep (k, n) {
        const int len = ss[k].size();
        const int a = ss[k][0]-'a', b = ss[k][len-1]-'a';
        rep (i, 26) old[i] = dp[a][i];
        dp[b][a] = max(dp[b][a], len);
        rep (i, 26) if (old[i] != -1) {
            dp[b][i] = max(dp[b][i], old[i] + len);
        }
    }
    int ans = 0;
    rep (i, 32) ans = max(ans, dp[i][i]);
    printf("%d\n", ans);
    return 0;
}
