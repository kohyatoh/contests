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
#define INF (1LL<<60)
#define MOD (YOUR_MODULUS)


class ConvexSequence {
    public:
    long long getMinimum(vector <int> a) {
        const int n = a.size();
        Int ans = 0;
        rep(l, n) for(int r=n-1; r>l; r--) {
            for(int i=l+1; i<r; i++) {
                const Int x = r-i, y = i-l;
                const Int des = (x*a[l]+y*a[r])/(x+y);
                if(a[i]>des) {
                    ans += a[i]-des;
                    a[i] = des;
                }
            }
        }
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
