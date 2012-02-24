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
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<28)
#define MOD (YOUR_MODULUS)
inline void cmax(int &a, int b) { if (a < b) a = b; }

string s;
int n;
string f[30];
int fb[32][32];
int dp[2][32];

int main() {
    cin >> s;
    cin >> n;
    rep (i, n) {
        cin >> f[i];
        const int a = f[i][0]-'a', b = f[i][1]-'a';
        fb[a][b] = fb[b][a] = 1;
    }
    int *cur = dp[0], *nxt = dp[1];
    rep (i, 32) cur[i] = -INF;
    rep (k, s.size()) {
        rep (i, 32) nxt[i] = cur[i];
        const int ix = s[k] - 'a';
        rep (i, 32) if (!fb[i][ix]) {
            cmax(nxt[ix], cur[i]+1);
        }
        cmax(nxt[ix], 1);
        swap(cur, nxt);
    }
    int ans = INF;
    rep (i, 32) ans = min(ans, (int)s.size()-cur[i]);
    printf("%d\n", ans);
    return 0;
}
