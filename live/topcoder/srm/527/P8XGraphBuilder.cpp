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
#define INF (1<<28)
#define MOD (YOUR_MODULUS)

inline void cmax(int &a, int b) { if(a<b) a = b; }

int n;
vector<int> S;
int dp[128][128];

class P8XGraphBuilder {
    public:
    int solve(vector <int> scores) {
        S = vector<int>(1, 0);
        rep(i, scores.size()) S.push_back(scores[i]);
        n = S.size();
        rep(i, 128) rep(j, 128) dp[i][j] = -INF;
        dp[1][0] = 0;
        for(int i=2; i<=n; i++) {
            for(int j=1; j<i; j++) {
                rep(x, i) rep(y, x) {
                    const int a = j==1 ? S[j] : dp[i-x][j-1]-S[j-1]+S[j];
                    const int b = dp[x][y]-S[y]+S[y+1];
                    cmax(dp[i][j], a+b);
                }
            }
        }
        int ans = -INF;
        rep(i, n) cmax(ans, dp[n][i]);
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
