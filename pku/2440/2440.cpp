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
#define INF MY_INFINITY
#define MOD (2005)

map<pair<int, pair<int, int> >, int> memo;

int rec(int len, int l, int r) {
    LOG(len); LOG(l); LOG(r);
    pair<int, pair<int, int> > sig(len, mp(l, r));
    if(memo.find(sig)!=memo.end()) return memo[sig];
    if(len==2) return l==r;
    const int h = len/2;
    int ans = 0;
    rep(i, 8) if(i!=5 && i!=7) {
        ans = (ans+rec(h+1, l, i%4)*rec(h+1-(len%2==0), i/2, r))%MOD;
    }
    return memo[sig] = ans;
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        int ans = 0;
        if(n<3) ans = 1<<n;
        else rep(i, 4) rep(j, 4) ans = (ans+rec(n, i, j))%MOD;
        printf("%d\n", ans);
    }
    return 0;
}


