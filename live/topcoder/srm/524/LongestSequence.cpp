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

#define M (100000)
vector<int> rl[2][M];

bool add_rule(int x, int y, int w) {
    vector<int> &a = rl[w][x];
    vector<int> &b = rl[1-w][x];
    rep(i, a.size()) if(a[i]==y) return true;
    a.push_back(y);
    rep(i, b.size()) if(b[i]==y) return false;
    rep(i, b.size()) {
        if(b[i]>y && !add_rule(y+1, b[i], 1-w)) return false;
        if(b[i]<y && !add_rule(b[i]+1, y, w)) return false;
    }
    return true;
}

class LongestSequence {
    public:
    int maxLength(vector <int> C) {
        bool all = true;
        rep(i, C.size()) if(C[0]*C[i]<0) all = false;
        if(all) return -1;
        rep(k, 2) rep(i, M) rl[k][i].clear();
        rep(k, M) rep(i, C.size()) if(abs(C[i])<=k+1) {
            if(!add_rule(k+1-abs(C[i]), k, C[i]>=0)) return k;
        }
        return -1;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
