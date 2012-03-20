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

const double pi = atan2(0, -1);

int dp[50][400];
char buf[1000];

class TurtleSpy {
public:
    double maxDistance(vector <string> commands) {
        int f = 0, b = 0;
        vector<int> rs;
        rep (i, commands.size()) {
            int x;
            sscanf(commands[i].c_str(), "%s %d", buf, &x);
            if (buf[0] == 'f') f += x;
            if (buf[0] == 'b') b += x;
            if (buf[0] == 'l') rs.push_back(360-x);
            if (buf[0] == 'r') rs.push_back(x);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        const int n = rs.size();
        rep (k, n) {
            rep (i, 360) dp[k+1][i] |= dp[k][i];
            rep (i, 360) {
                const int ni = (i + rs[k]) % 360;
                dp[k+1][ni] |= dp[k][i];
            }
        }
        double ans = 0;
        rep (i, 360) if (dp[n][i]) {
            const double x = f - b * cos(i/180.0*pi);
            const double y = -b * sin(i/180.0*pi);
            ans = max(ans, sqrt(x*x+y*y));
        }
        return ans;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"forward 100", "backward 100", "left 90" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 141.4213562373095; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 40.58520737741619; verify_case(2, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
    TurtleSpy ___test;
    ___test.run_test(-1);
}

// END CUT HERE
