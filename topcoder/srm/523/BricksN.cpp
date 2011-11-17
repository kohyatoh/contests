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
#define MOD (1000000007LL)
inline void addmod(Int &a, Int b) { a = (a+b)%MOD; }

Int sub[128], dp[128][128];

class BricksN {
    public:
    int countStructures(int w, int h, int K) {
        memset(sub, 0, sizeof(sub));
        sub[0] = 1;
        rep(k, w) rep(i, K) if(k+i+1<=w) addmod(sub[k+i+1], sub[k]);
        rep(i, w+1) dp[0][i] = 1;
        for(int k=1; k<=h; k++) for(int u=0; u<=w; u++) {
            dp[k][u] = 1;
            for(int c=1; c<=u; c++) {
                const Int a = dp[k-1][c]*sub[c]%MOD;
                for(int x=0; x<u-c; x++) addmod(dp[k][u], dp[k][u-c-x-1]*a);
                addmod(dp[k][u], a);
            }
        }
        return dp[h][w];
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
