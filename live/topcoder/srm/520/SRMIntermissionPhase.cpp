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
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (1000000007)

Int way[8][300000], dp[2][300000], sum[300000];

Int calc(int l, int r) {
    if(l>r) return 0;
    return (sum[r+1]-sum[l]+MOD)%MOD;
}

class SRMIntermissionPhase {
    public:
    int countWays(vector <int> pt, vector <string> desc) {
        memset(way, 0, sizeof(way));
        memset(dp, 0, sizeof(dp));
        way[0][0] = 1;
        rep(k, 3) for(int i=1; i<=pt[k]; i++) way[1<<k][i] = 1;
        rep(k, 3) {
            memset(sum, 0, sizeof(sum));
            rep(i, 250000) sum[i+1] = (sum[i]+way[1<<k][i])%MOD;
            rep(j, k) rep(i, 250000) if(i>0) {
                way[(1<<j)|(1<<k)][i] = calc(max(1, i-pt[j]), i-1);
            }
        }
        memset(sum, 0, sizeof(sum));
        rep(i, 250000) sum[i+1] = (sum[i]+way[6][i])%MOD;
        rep(i, 250000) if(i>0) way[7][i] = calc(max(1, i-pt[0]), i-1);
        const int n = desc.size();
        Int *cur = dp[0], *nxt = dp[1];
        for(int k=n-1; k>=0; k--) {
            sum[0] = k==n-1 ? 1 : 0;
            rep(i, 250000) sum[i+1] = (sum[i]+cur[i])%MOD;
            int b = 0;
            rep(i, 3) if(desc[k][i]=='Y') b|=1<<i;
            rep(i, 250000) nxt[i] = sum[i]*way[b][i]%MOD;
            swap(cur, nxt);
        }
        Int ans = 0;
        rep(i, 250000) ans = (ans+cur[i])%MOD;
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
