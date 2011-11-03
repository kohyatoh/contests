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

Int fact(int n) {
    Int r = 1;
    rep(i, n) r *= (i+1);
    return r;
}

int main() {
    vector<Int> xs;
    rep(k, 12) if(k>0) {
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

    int n, k;
    scanf("%d%d", &n, &k);
    int w = n-1;
    while(w>=0 && fact(n-w)<k) w--;
    if(w<0) {
        printf("%d\n", -1);
        return 0;
    }
    vector<int> rs, ts;
    for(int i=w; i<n; i++) ts.push_back(i+1);
    for(int i=w; i<n; i++) {
        if(ts.size()==1) rs.push_back(ts[0]);
        else {
            int ix = 0;
            while(k>fact(n-i-1)) {
                k -= fact(n-i-1);
                ix++;
            }
            rs.push_back(ts[ix]);
            ts.erase(ts.begin()+ix);
        }
    }
    rep(i, rs.size()) LOG(rs[i]);
    int ans = 0;
    rep(i, xs.size()) {
        if(xs[i]<=w) ans += 1;
        else if(xs[i]<=n) {
            const int x = rs[xs[i]-w-1];
            if(binary_search(xs.begin(), xs.end(), x)) ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}


