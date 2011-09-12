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

int n, a[50000], dp1[50000], dp2[50000];

int main() {
    int T, s, mn;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        s=0, mn=0;
        rep(i, n) {
            s += a[i];
            if(i==0) dp1[i] = s - mn;
            else dp1[i] = max(dp1[i-1], s-mn);
            mn = min(mn, s);
        }
        s=0, mn=0;
        for(int i=n-1; i>=0; i--) {
            s += a[i];
            if(i==n-1) dp2[i] = s - mn;
            else dp2[i] = max(dp2[i+1], s-mn);
            mn = min(mn, s);
        }
        int ans = s;
        rep(i, n-1) ans = max(ans, dp1[i]+dp2[i+1]);
        printf("%d\n", ans);
    }
    return 0;
}


