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
#define MOD (1000000007LL)

Int L[128], dp[128];
string W, A, D, S, F;

char at(int k, Int i) {
    if (i < 0 || i >= L[k]) return 0;
    if (k == 0) return S[i];
    else {
        if (i < (Int)W.size()) return W[i];
        i -= W.size();
        if (i < L[k-1]) return at(k-1, i);
        i -= L[k-1];
        if (i < (Int)A.size()) return A[i];
        i -= A.size();
        if (i < L[k-1]) return at(k-1, i);
        i -= L[k-1];
        return D[i];
    }
}

bool match(int k, Int st) {
    rep (i, F.size()) {
        if (at(k, st+i) != F[i]) return false;
    }
    return true;
}

class AkariDaisukiDiv1 {
public:
    int countF(string _W, string _A, string _D, string _S, string _F, int K) {
        W = _W;
        A = _A;
        D = _D;
        S = _S;
        F = _F;
        L[0] = S.size();
        rep (i, 100) {
            L[i+1] = min(INF, (Int)(W.size()+L[i]+A.size()+L[i]+D.size()));
        }
        memset(dp, 0, sizeof(dp));
        rep (i, S.size()) {
            if (match(0, i)) dp[0]++;
        }
        int m = 1;
        Int la = 0;
        while (m <= 80 && L[m] < INF) {
            Int z = 0;
            rep (i, W.size()) if (match(m, i)) dp[m]++;
            z += W.size() + L[m-1];
            rep (i, F.size()-1) {
                const Int ix = z - 1 - i;
                if (ix >= z-L[m-1] && match(m, ix)) dp[m]++;
            }
            rep (i, A.size()) if (match(m, z+i)) dp[m]++;
            z += A.size() + L[m-1];
            rep (i, F.size()-1) {
                const Int ix = z - 1 - i;
                if (ix >= z-L[m-1] && match(m, ix)) dp[m]++;
            }
            rep (i, D.size()) if (match(m, z+i)) dp[m]++;
            la = dp[m];
            LOG(m);
            dp[m] = (dp[m] + 2*dp[m-1]) % MOD;
            m++;
        }
        if (K < m) return dp[K];
        LOG(K);
        Int ans = dp[m-1];
        while (m <= K) {
            ans = (la + 2*ans) % MOD;
            m++;
        }
        return ans;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
