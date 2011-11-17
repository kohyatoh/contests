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

const char dat[22] = "ABCDEFZHIKLMNOPQRSTVX";
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct L {
    int x, y, b;
    L() {}
    L(int x, int y, int b) : x(x), y(y), b(b) {}
};

int w, h, f[32][32], cnt[1<<21];

Int solve(int sx, int sy) {
    if(f[sx][sy]==0) return 0;
    queue<pair<int, L> > q;
    q.push(mp(0, L(sx, sy, f[sx][sy])));
    vector<int> z;
    while(!q.empty()) {
        const pair<int, L> vv(q.front());
        q.pop();
        const int x = vv.second.x, y = vv.second.y, b = vv.second.b;
        if(vv.first==10) {
            z.push_back(b);
            cnt[b]++;
        }
        else rep(d, 4) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(f[nx][ny] && (b&f[nx][ny])==0) {
                q.push(mp(vv.first+1, L(nx, ny, b|f[nx][ny])));
            }
        }
    }
    Int ans = 0;
    rep(i, z.size()) ans += cnt[(1<<21)-1-z[i]+f[sx][sy]];
    rep(i, z.size()) cnt[z[i]] = 0;
    return ans;
}

class AlphabetPaths {
    public:
    long long count(vector <string> lm) {
        const string tbl(dat);
        memset(f, 0, sizeof(f));
        rep(i, lm.size()) rep(j, lm[i].size()) if(lm[i][j]!='.') {
            f[i+1][j+1] = 1<<tbl.find(lm[i][j]);
        }
        w = lm.size()+2;
        h = lm[0].size()+2;
        Int ans = 0;
        rep(i, w) rep(j, h) ans += solve(i, j);
        return ans;
    }


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
