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
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

int main() {
    int L, R;
    scanf("%d%d", &L, &R);
    vector<Int> xs;
    rep(k, 12) {
        const int kk = 1<<k;
        rep(b, kk) {
            Int a = 0;
            rep(i, k) a = a*10+(b&(1<<i) ? 7 : 4);
            xs.push_back(a);
        }
    }
    sort(xs.begin(), xs.end());
    LOG(xs.size());
    rep(i, 10) LOG(xs[i]);
    Int ans = 0;
    rep(i, xs.size()-1) if(L<=R) {
        if(xs[i]<L && L<=xs[i+1]) {
            ans += (min(xs[i+1], (Int)R)-L+1)*xs[i+1];
            L = xs[i+1]+1;
        }
    }
    cout << ans << endl;
    return 0;
}

