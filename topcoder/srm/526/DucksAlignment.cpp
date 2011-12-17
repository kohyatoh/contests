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
#define INF (1<<28)
#define MOD (YOUR_MODULUS)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int n, m, is[64][64];

int calc() {
    int ans = INF;
    rep(y, m) {
        int b = 0;
        vector<int> ys;
        rep(i, n) {
            rep(j, m) if(is[i][j]) {
                ys.push_back(i);
                b += abs(y-j);
                break;
            }
        }
        rep(x, n) {
            int a = b, cur = x;
            rep(i, ys.size()) {
                if(cur>=n) a = INF;
                a += abs(ys[i]-cur);
                cur++;
            }
            cmin(ans, a);
        }
    }
    return ans;
}

class DucksAlignment {
    public:
    int minimumTime(vector <string> g) {
        int ans = INF;
        n = g.size(); m = g[0].size();
        rep(i, n) rep(j, m) is[i][j] = g[i][j]=='o';
        cmin(ans, calc());
        swap(n, m);
        rep(i, n) rep(j, m) is[i][j] = g[j][i]=='o';
        cmin(ans, calc());
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
