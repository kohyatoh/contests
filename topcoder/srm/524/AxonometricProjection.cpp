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
#define MOD (1000000009LL)

struct St {
    int x, y, p, q;
    St(int x, int y, int p, int q) : x(x), y(y), p(p), q(q) {}
};
bool operator<(const St& l, const St& r) {
    if(l.x!=r.x) return l.x<r.x;
    if(l.y!=r.y) return l.y<r.y;
    if(l.p!=r.p) return l.p<r.p;
    if(l.q!=r.q) return l.q<r.q;
    return false;
}

map<St, int> memo;
Int pw[300], pw1[300], C[300][300];

int rec(int x, int y, int p, int q) {
    St sig(x, y, p, q);
    if(memo.count(sig)) return memo[sig];
    Int ans = 0;
    if(y==0) {
        ans = 1;
        rep(_, x) ans = ans*(pw[q]-pw1[q]+MOD)%MOD;
    }
    else {
        rep(k, x+1) {
            Int m = C[x][k];
            m = m*pw1[x-k]%MOD;
            if(k==0) m = m*(pw[p]-pw1[p]+MOD)%MOD;
            else m = m*pw[p]%MOD;
            if(q) rep(_, k) m = m*pw[q]%MOD;
            m = m*rec(x-k, y-1, p+k, q)%MOD;
            ans = (ans+m)%MOD;
        }
    }
//    printf("rec %d, %d, %d, %d =  %d\n", x, y, p, q, (int)ans);
    return memo[sig] = ans;
}

int calc(int h, int x, int y, int p, int q) {
    pw[0] = pw1[0] = 1;
    rep(i, 200) pw[i+1] = (pw[i]*(h+1))%MOD;
    rep(i, 200) pw1[i+1] = (pw1[i]*h)%MOD;
    memo.clear();
//    printf("%d, %d, %d, %d, %d\n", h, x, y, p, q);
//    printf("h = %d, ans = %d\n", h, rec(x, y, p, q));
    return rec(x, y, p, q);
}

class AxonometricProjection {
    public:
    int howManyWays(vector <int> xs, vector <int> ys) {
        memset(C, 0, sizeof(C));
        C[0][0] = 1;
        rep(i, 200) rep(j, 200) {
            C[i+1][j] += C[i][j];
            C[i+1][j] %= MOD;
            C[i+1][j+1] += C[i][j];
            C[i+1][j+1] %= MOD;
        }
        vector<int> hs;
        rep(i, xs.size()) hs.push_back(xs[i]);
        rep(i, ys.size()) hs.push_back(ys[i]);
        sort(hs.begin(), hs.end());
        hs.erase(unique(hs.begin(), hs.end()), hs.end());
        Int ans = 1;
        rep(k, hs.size()) {
            int x = 0, p = 0;
            rep(i, xs.size()) {
                if(xs[i]==hs[k]) x++;
                if(xs[i]>hs[k]) p++;
            }
            int y = 0, q = 0;
            rep(i, ys.size()) {
                if(ys[i]==hs[k]) y++;
                if(ys[i]>hs[k]) q++;
            }
            ans *= calc(hs[k], x, y, p, q);
            ans %= MOD;
        }
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
