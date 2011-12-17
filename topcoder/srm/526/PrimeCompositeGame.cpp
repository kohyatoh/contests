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

int N, K;
int is[2][500000];
int dp[2][500000];

struct S {
    set<pair<int, int> > w, l;
    void remove(int x, int *a) {
        if(x-K>=0) {
            if(a[x-K]<=0) l.erase(mp(-a[x-K], x-K));
            else w.erase(mp(-a[x-K], x-K));
        }
    }
    void update(int x, int *a) {
        if(a[x]<=0) l.insert(mp(-a[x], x));
        else w.insert(mp(-a[x], x));
    }
    int query() {
        if(!l.empty()) {
            return (*l.begin()).first+1;
        }
        else if(!w.empty()) {
            return (*w.begin()).first-1;
        }
        else return 0;
    }
};

class PrimeCompositeGame {
    public:
    int theOutcome(int _N, int _K) {
        N = _N;
        K = _K;
        memset(is, -1, sizeof(is));
        rep(i, 2) is[0][i] = is[1][i] = 0;
        for(int i=2; i<500000; i++) if(is[0][i]) {
            is[1][i] = 0;
            for(int j=i+i; j<500000; j+=i) is[0][j] = 0;
        }
        S s1, s2;
        rep(i, N) {
            dp[0][i] = s2.query();
            dp[1][i] = s1.query();
            s1.remove(i, dp[0]);
            s2.remove(i, dp[1]);
            if(is[1][i]) s1.update(i, dp[0]);
            if(is[0][i]) s2.update(i, dp[1]);
        }
        return s2.query();
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
