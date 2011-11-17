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


class CountingSeries {
    public:
    long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
        Int ans = 0;
        if(upperBound >= a) {
            ans += 1 + (upperBound-a)/b;
        }
        for(Int x=1; x<=upperBound; x*=d) {
            if((double)c*x<=upperBound) {
                const Int z = c*x;
                if(z<=upperBound) {
                    if(z<a || (z-a)%b!=0) ans++;
                }
            }
            if(d==1) break;
        }
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
