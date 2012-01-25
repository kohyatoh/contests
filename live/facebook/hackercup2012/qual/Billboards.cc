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

int W, H;
vector<int> ls;

int calc(int a) {
    int c = 1, p = 0;
    rep (i, ls.size()) {
        const int w = ls[i] * a;
        if (w > W) return INF;
        if (p + w > W) {
            c++;
            p = 0;
        }
        p += w + a;
    }
    return c * a;
}

int solve() {
    for (int i = H; i > 0; i--) if (calc(i) <= H) return i;
    return 0;
}

int main() {
    string buf;
    getline(cin, buf);
    const int T = atoi(buf.c_str());
    rep(t, T) {
        getline(cin, buf);
        istringstream sin(buf);
        sin >> W >> H;
        ls.clear();
        string s;
        while (sin >> s) ls.push_back(s.size());
        const int ans = solve();
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
