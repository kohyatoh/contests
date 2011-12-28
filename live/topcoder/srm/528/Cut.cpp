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


class Cut {
    public:
    int getMaximum(vector <int> el, int maxCuts) {
        vector<int> a, b;
        rep(i, el.size()) {
            if (el[i] % 10 == 0) a.push_back(el[i]/10);
            else b.push_back(el[i]/10);
        }
        sort(a.begin(), a.end());
        int ans = 0, r = maxCuts;
        rep(i, a.size()) {
            if (a[i]-1 <= r) {
                ans += a[i];
                r -= (a[i]-1);
            }
            else {
                ans += r;
                r -= r;
            }
        }
        rep(i, b.size()) {
            const int k = min(b[i], r);
            ans += k;
            r -= k;
        }
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
