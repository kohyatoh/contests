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
inline void cmax(pair<Int, Int>& a, const pair<Int, Int>& b) {
    if (a < b) a = b;
}

int n, bs[80], m, ms[80];
int sz, of[80];
pair<Int, Int> dp[64][64];

void simulate() {
    sz = min(n, ms[0]);
    vector<int> xs[2];
    rep (i, sz) xs[1].push_back(i);
    for (int i = 1; i < m; i++) {
        const int a = i%2;
        sort(xs[a].begin(), xs[a].end());
        rep (_, ms[i]) {
            if (xs[a].size() == 0) break;
            xs[1-a].push_back(xs[a].back());
            xs[a].pop_back();
        }
    }
    rep (k, 2) {
        rep (i, xs[k].size()) of[sz-1-xs[k][i]] = k;
    }
}

class HeavyBooks {
public:
    vector <int> findWeight(vector <int> books, vector <int> moves) {
        n = books.size();
        rep (i, n) bs[i] = books[i];
        sort(bs, bs+n);
        reverse(bs, bs+n);
        m = moves.size();
        rep (i, m) ms[i] = moves[i];
        simulate();
        rep (i, 64) rep (j, 64) dp[i][j] = mp(-INF, -INF);
        dp[0][0] = mp(0, 0);
        rep (i, sz) rep (j, n) {
            cmax(dp[i][j+1], dp[i][j]);
            const int w = bs[j];
            if (of[i] == 0) {
                cmax(dp[i+1][j+1], mp(dp[i][j].first-w, dp[i][j].second+w));
            }
            else {
                cmax(dp[i+1][j+1], mp(dp[i][j].first+w, dp[i][j].second+w));
            }
        }
        pair<Int, Int> ans = mp(-INF, -INF);
        rep (i, n+1) cmax(ans, dp[sz][i]);
        const Int a = ans.first;
        const Int b = ans.second;
        vector<int> ansv;
        ansv.push_back((b-a)/2);
        ansv.push_back((b+a)/2);
        return ansv;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
