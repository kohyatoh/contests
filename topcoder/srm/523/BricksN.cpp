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
#define INF (MY_INF)
#define MOD (1000000007LL)
inline void addmod(Int &a, Int b) { a = (a+b)%MOD; }

Int sub[128][128], mul[128], dp[128][128];

Int rec(int w, int h) {
    if(h==0) return 1;
    if(w<=0) return 1;
    if(dp[w][h]!=-1) return dp[w][h];
    Int ans = 1;
    rep(x, w+1) if(x>0) {
        const Int a = rec(x, h-1)*mul[x]%MOD;
        rep(s, w+1) if(s+x<=w) {
            addmod(ans, rec(w-s-x-1, h)*a%MOD);
        }
    }
    return dp[w][h] = ans;
}

class BricksN {
    public:
    int countStructures(int w, int h, int K) {
        memset(sub, 0, sizeof(sub));
        sub[0][0] = 1;
        rep(k, w) rep(x, w) for(int i=1; i<=K; i++) {
            if(x+i<=w) addmod(sub[k+1][x+i], sub[k][x]);
        }
        memset(mul, 0, sizeof(mul));
        rep(k, w) rep(i, w+1) addmod(mul[i], sub[k+1][i]);
        memset(dp, -1, sizeof(dp));
        return rec(w, h);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 13; verify_case(0, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 3; int Arg3 = 83; verify_case(1, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 6; verify_case(2, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 3; int Arg3 = 288535435; verify_case(3, Arg3, countStructures(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {
    BricksN ___test;
    ___test.run_test(-1);
}
// END CUT HERE
