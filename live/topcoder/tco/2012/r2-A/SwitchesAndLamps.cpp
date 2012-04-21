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
typedef long long Int;
#define INF (1<<28)
#define MOD (YOUR_MODULUS)

int dp[128];

class SwitchesAndLamps {
public:
    int theMin(vector <string> sw, vector <string> la) {
        rep (i, 128) dp[i] = INF;
        dp[0] = dp[1] = 0;
        for (int i = 2; i < 128; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + dp[i-j] + 1);
            }
        }
        const int n = sw[0].size();
        const int m = sw.size();
        map<Int, int> sc, lc;
        rep (i, n) {
            Int sig = 0;
            rep (j, m) sig = sig*2 + (sw[j][i] == 'Y');
            sc[sig]++;
        }
        rep (i, n) {
            Int sig = 0;
            rep (j, m) sig = sig*2 + (la[j][i] == 'Y');
            lc[sig]++;
        }
        int ans = 0;
        for (map<Int, int>::iterator it = sc.begin(); it != sc.end(); ++it) {
            const Int sig = it->first;
            if (lc[sig] != sc[sig]) return -1;
            LOG(sc[sig]);
            ans = max(ans, dp[sc[sig]]);
        }
        return ans;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
