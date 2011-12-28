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
#define MOD (YOUR_MODULUS)

int n, w;
char f[64], t[64];
Int dp[64][64];

Int calc(int b) {
    const int h = n/2;
    rep(i, h) t[i] = (b&(1<<i)) ? 'x' : 'o';
    t[h] = 0;
    rep(i, n+1) rep(j, h+1) dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i, n) {
        const int m = min(h+1, i+1);
        rep(j, m) if (dp[i][j]) {
            const int x = i-j;
            const int y = j;
            if (f[i]==t[x]) {
                dp[i+1][j] += dp[i][j];
            }
            if (f[i]==t[y]) {
                dp[i+1][j+1] += dp[i][j];
            }
        }
    }
    return dp[n][h];
}

class SPartition {
    public:
    long long getCount(string s) {
        n = s.size();
        rep(i, n) f[i] = s[i];
        w = 0;
        rep(i, n) if (f[i]=='x') w++;
        if (w%2==1) return 0;
        Int ans = 0;
        const int hn = n/2, hw = w/2;
        int comb = (1 << hw) - 1;
        const int nn = 1<<hn;
        while (comb < nn) {
            ans += calc(comb);
            if (hw == 0) break;
            const int x = comb & -comb, y = comb + x;
            comb = ((comb&~y)/x >> 1) | y;
        }
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
