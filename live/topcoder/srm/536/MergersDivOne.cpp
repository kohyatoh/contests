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
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

double dp[100];

class MergersDivOne {
public:
    double findMaximum(vector <int> a) {
        const int n = a.size();
        rep (i, 100) dp[i] = -1e100;
        sort(a.begin(), a.end());
        dp[0] = a[0];
        for (int i = 0; i < n; i++) {
            double sum = dp[i];
            for (int j = 1; i+j < n; j++) {
                sum += a[i+j];
                dp[i+j] = max(dp[i+j], sum / (j+1));
            }
        }
        return dp[n-1];
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
