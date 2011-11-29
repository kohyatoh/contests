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

int n;
vector<int> g[32];
vector<int> fs;
int ha[32], hb[32];

bool allhear(int t) {
    rep(i, n) if(ha[i]>t || hb[i]>t) return false;
    return true;
}

void spread(int ix, int t, int *a) {
    LOG(ix);
    LOG(t);
    rep(i, g[ix].size()) {
        const int to = g[ix][i];
        a[to] = min(a[to], t+1);
    }
}

int solve(int bit) {
    rep(i, 32) ha[i] = hb[i] = INF;
//    rep(i, 32) q[0][i].clear(), q[1][i].clear();
    rep(i, fs.size()) {
        const int ix = fs[i];
        ha[ix] = hb[ix] = 0;
    }
    rep(t, 20) {
//        LOG(t);
//        rep(i, n) LOG(ha[i]), LOG(hb[i]);
        if(allhear(t)) return t;
        rep(i, n) {
            if(ha[i]==hb[i]) {
                if(bit&(1<<i)) {
                    if(ha[i]==t) spread(i, t, ha);
                    if(ha[i]==t-1) spread(i, t, hb);
                }
                else {
                    if(ha[i]==t) spread(i, t, hb);
                    if(ha[i]==t-1) spread(i, t, ha);
                }
            }
            else if(ha[i]==t) spread(i, t, ha);
            else if(hb[i]==t) spread(i, t, hb);
        }
    }
    return INF;
}

class Rumor {
    public:
    int getMinimum(string knowledge, vector <string> graph) {
        fs.clear();
        rep(i, 32) g[i].clear();

        n = knowledge.size();
        rep(i, n) if(knowledge[i]=='Y') fs.push_back(i);
        rep(i, n) rep(j, n) if(graph[i][j]=='Y') g[i].push_back(j);

        int ans = INF;
        const int nn = 1<<n;
//        ans = solve(0);
        rep(i, nn) ans = min(ans, solve(i));
        return ans<INF ? ans : -1;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
