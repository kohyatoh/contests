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

Int aabs(Int x) { return x > 0 ? x : -x; }

int n;
Int x[128];
Int g[128][128];
Int dp[128][128];

Int calc(Int a, Int b) {
    Int ans = 0;
    rep (k, n) if (a <= x[k] && x[k] <= b) {
        if (k != 0) ans += min(aabs(x[k]-a), aabs(x[k]-b));
        if (k != n-1) ans += min(aabs(x[k]-a), aabs(x[k]-b));
    }
    rep (k, n-1) if (a <= x[k] && x[k] <= b && a <= x[k+1] && x[k+1] <= b) {
        Int z = 0;
        z += min(aabs(x[k]-a), aabs(x[k]-b));
        z += min(aabs(x[k+1]-a), aabs(x[k+1]-b));
        if (aabs(x[k+1] - x[k]) < z) {
            ans -= z;
            ans += aabs(x[k+1] - x[k]);
        }
    }
    return ans;
}

class CucumberWatering {
public:
    long long theMin(vector <int> _x, int K) {
        n = _x.size();
        rep (i, n) x[i] = _x[i];
        rep (i, 128) rep (j, 128) dp[i][j] = INF;
        vector<pair<Int, int> > ps;
        rep (i, n) ps.push_back(mp(x[i], i));
        sort(ps.begin(), ps.end());
        rep (j, n) rep (i, j) {
            const Int a = ps[i].first;
            const Int b = ps[j].first;
            g[i][j] = calc(a, b);
        }
        rep (i, n) {
            dp[1][i] = calc(-INF, ps[i].first);
        }
        for (int k = 2; k <= K; k++) {
            rep (j, n) rep (i, j) {
                dp[k][j] = min(dp[k][j], dp[k-1][i] + g[i][j]);
            }
        }
        Int ans = 0;
        rep (i, n-1) ans += aabs(x[i]-x[i+1]);
        for (int k = 1; k <= K; k++) {
            rep (i, n) ans = min(ans, dp[k][i] + calc(ps[i].first, INF));
        }
        return ans;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 6, 8, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 6LL; verify_case(0, Arg2, theMin(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1000000000, 1000000000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 3000000000LL; verify_case(1, Arg2, theMin(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {58, 2012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; long long Arg2 = 0LL; verify_case(2, Arg2, theMin(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 58LL; verify_case(3, Arg2, theMin(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
    CucumberWatering ___test;
    ___test.run_test(-1);
}

// END CUT HERE
