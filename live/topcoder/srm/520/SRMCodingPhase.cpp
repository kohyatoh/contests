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


class SRMCodingPhase {
    public:
    int countScore(vector <int> pt, vector <int> sk, int luck) {
        int ans = 0;
        int ix[3];
        for(ix[0]=0; ix[0]<=luck; ix[0]++) {
            for(ix[1]=0; ix[1]<=luck-ix[0]; ix[1]++) {
                ix[2] = luck-ix[0]-ix[1];
                rep(b, 1<<3) {
                    int p = 0, s = 0;
                    rep(i, 3) if(b&(1<<i)) {
                        const int t = max(1, sk[i]-ix[i]);
                        p += max(0, pt[i]-(2<<i)*t);
                        s += t;
                    }
                    if(s<=75) ans = max(ans, p);
                }
            }
        }
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
