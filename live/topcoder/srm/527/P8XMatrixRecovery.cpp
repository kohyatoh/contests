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

struct BiMatching {
    static const int N=64;
    int h, w, g[N][N];
    int vis[N], cvis, mat[N];
    void init(int _h, int _w) { h=_h; w=_w; memset(g, 0, sizeof(g)); }
    void add_edge(int _u, int _v) { g[_u][_v]=1; }
    bool rec(int at) {
        if(at<0) return true;
        rep(i, w) if(g[at][i] && vis[i]!=cvis) {
            vis[i] = cvis;
            if(rec(mat[i])) {
            mat[i] = at;
                return true;
            }
        }
        return false;
    }
    int match() {
        memset(mat, -1, sizeof(mat));
        memset(vis, -1, sizeof(vis));
        int r=0;
        rep(i, h) {
            cvis = i;
            if(rec(i)) r++;
        }
        return r;
    }
} bm;

bool f(const vector<string>& R, const vector<string>& C) {
    const int n = R.size();
    const int m = R[0].size();
    bm.init(m, m);
    rep(i, m) rep(j, m) {
        bool ok = true;
        rep(k, n) {
            if(R[k][i]!='?' && C[j][k]!='?' && R[k][i]!=C[j][k]) ok = false;
        }
        if(ok) bm.add_edge(i, j);
    }
    return bm.match()==m;
}

class P8XMatrixRecovery {
    public:
    vector <string> solve(vector <string> rows, vector <string> columns) {
        const int n = rows.size();
        const int m = rows[0].size();
        rep(i, n) rep(j, m) if(rows[i][j]=='?') {
            rows[i][j] = '0';
            if(f(rows, columns)==false) rows[i][j] = '1';
        }
        return rows;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
