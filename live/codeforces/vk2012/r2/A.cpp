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
#define MOD (1000000007)
inline void add(int &a, Int b) { a = (a+b) % MOD; }

string s, t;
int dp[6000][6000];

int main() {
    cin >> s >> t;
    rep (i, s.size()+1) rep (j, t.size()) {
        add(dp[i][j+1], dp[i][j]);
        if (i < (int)s.size() && s[i] == t[j]) {
            add(dp[i+1][j+1], dp[i][j]+1);
        }
    }
    int ans = 0;
    rep (i, s.size()+1) add(ans, dp[i][t.size()]);
    cout << ans << endl;
    return 0;
}
