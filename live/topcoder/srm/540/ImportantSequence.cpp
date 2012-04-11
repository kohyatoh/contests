#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
#define INF (1LL<<60)
#define MOD (YOUR_MODULUS)


Int x[64], y[64];

class ImportantSequence {
public:
    int getCount(vector <int> B, string op) {
        const int n = B.size()+1;
        rep (i, n) x[i] = 1;
        rep (i, n) y[i] = INF;
        rep (i, n-1) {
            if (op[i] == '+') {
                y[i] = min(y[i], B[i]-1LL);
                x[i+1] = max(x[i+1], B[i]-y[i]);
                y[i+1] = min(y[i+1], B[i]-x[i]);
            }
            else {
                x[i+1] = max(x[i+1], x[i]-B[i]);
                y[i+1] = min(y[i+1], y[i]-B[i]);
            }
        }
        Int ans = INT_MAX;
        rep (i, n) ans = min(ans, y[i]+1-x[i]);
        if (ans >= INT_MAX) return -1;
        return max(0LL, ans);
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
