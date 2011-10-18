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

int n, m, a[64][64], b[3], s[64], tmp[64][64];

int solve() {
    vector<int> as(3), ts(3);
    rep(i, 3) ts[i] = b[i];
    sort(ts.begin(), ts.end());
    memset(s, 0, sizeof(s));
    rep(i, n) rep(j, m) s[i] += a[i][j];
    rep(i, n-1) s[i+1] += s[i];
    int ans = 0;
    rep(i, n) for(int j=i+2; j<n; j++) {
        as[0] = s[i];
        as[1] = s[j-1]-s[i];
        as[2] = s[n-1]-s[j-1];
        sort(as.begin(), as.end());
        if(as==ts) ans++;
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) scanf("%d", a[i]+j);
    rep(i, 3) scanf("%d", b+i);
    int ans = 0;
    ans += solve();
    rep(i, n) rep(j, m) tmp[i][j] = a[i][j];
    rep(i, n) rep(j, m) a[j][i] = tmp[i][j];
    swap(n, m);
    ans += solve();
    printf("%d\n", ans);
    return 0;
}


