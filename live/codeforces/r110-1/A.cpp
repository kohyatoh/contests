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

inline void cmin(int &a, int b) { if (a > b) a = b; }

string s, u;

int main() {
    cin >> s >> u;
    s = string(u.size()*2, '_') + s + string(u.size()*2, '_');
    int ans = INF;
    rep (i, s.size()-u.size()) {
        int c = 0;
        rep (j, u.size()) {
            c += s[i+j] != u[j];
        }
        cmin(ans, c);
    }
    printf("%d\n", ans);
    return 0;
}
