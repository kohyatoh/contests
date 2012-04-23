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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int used[128];

class AntsMeet {
public:
    int countAnts(vector <int> x, vector <int> y, string directions) {
        memset(used, -1, sizeof(used));
        const int n = x.size();
        rep (i, n) x[i] *= 2;
        rep (i, n) y[i] *= 2;
        vector<int> dirs;
        rep (i, n) {
            if (directions[i] == 'N') dirs.push_back(3);
            if (directions[i] == 'E') dirs.push_back(0);
            if (directions[i] == 'S') dirs.push_back(1);
            if (directions[i] == 'W') dirs.push_back(2);
        }
        rep (t, 20000) {
            map<pair<int, int>, int> cnt;
            rep (i, n) if (used[i] == -1) {
                cnt[mp(x[i], y[i])]++;
            }
            rep (i, n) if (used[i] == -1) {
                if (cnt[mp(x[i], y[i])] > 1) {
                    used[i] = 1;
                }
            }
            rep (i, n) x[i] += dx[dirs[i]];
            rep (i, n) y[i] += dy[dirs[i]];
        }
        int ans = 0;
        rep (i, n) if (used[i] == -1) ans++;
        return ans;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
