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
#define INF (1LL<<60)
#define MOD (YOUR_MODULUS)

Int f(Int a, Int b) {
    if (a <= 0) return 0;
    return (a+b-1) / b;
}

int is[100];

class BlurredDartboard {
public:
    int minThrows(vector <int> points, int P) {
        const int n = points.size();
        memset(is, 0, sizeof(is));
        int pp = 0;
        rep (i, n) {
            is[points[i]] = 1;
            pp = max(pp, points[i]);
        }
        vector<int> qs;
        for (int i = 1; i <= n; i++) {
            if (!is[i]) qs.push_back(i);
        }
        const int m = qs.size();
        if (m == 0) return f(P, pp);
        Int sum = 0;
        rep (i, m) sum += qs[i];
        Int ans = INF;
        rep (k, m+1) {
            Int Q = P;
            rep (i, k) Q -= qs[i];
            ans = min(ans, k+f(Q, sum)*m);
            if (pp != 0) {
                ans = min(ans, k+f(Q, pp));
                rep (i, m+1) {
                    ans = min(ans, k+i+f(Q-pp*i, sum)*m);
                }
            }
        }
        return ans;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
