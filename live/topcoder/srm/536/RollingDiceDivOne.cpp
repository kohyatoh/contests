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
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

Int dp[100][1000];

class RollingDiceDivOne {
public:
    long long mostLikely(vector <int> dice) {
        const int n = dice.size();
        sort(dice.begin(), dice.end());
        reverse(dice.begin(), dice.end());
        Int lo = 1, hi = dice[0];
        for (int i = 1; i < n; i++) {
            Int l = lo+dice[i], r = hi+1;
            if (l <= r) {
                lo = l;
                hi = r;
            }
            else {
                if ((l-r)%2==0) {
                    lo = hi = (l+r)/2;
                }
                else {
                    lo = (l+r)/2;
                    hi = (l+r)/2+1;
                }
            }
        }
        return lo;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6, 6, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 11LL; verify_case(0, Arg1, mostLikely(Arg0)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, mostLikely(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(2, Arg1, mostLikely(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 10, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(3, Arg1, mostLikely(Arg0)); }
	void test_case_4() { int Arr0[] = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4366828428LL; verify_case(4, Arg1, mostLikely(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
    RollingDiceDivOne ___test;
    ___test.run_test(-1);
}

// END CUT HERE
