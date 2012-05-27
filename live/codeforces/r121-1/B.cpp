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

int n, k;
Int b, a[200000], sum[200000];
pair<Int, int> of[200000];

int main() {
    cin >> n >> k >> b;
    rep (i, n) cin >> a[i];
    a[n-1] = 0;
    rep (i, n) of[i] = mp(a[i], i);
    sort(of, of+n);
    reverse(of, of+n);
    rep (i, n) sum[i+1] = sum[i] + of[i].first;
    int ans = n;
    rep (i, k-1) {
        if (sum[k] > b) ans = min(ans, of[i].second+1);
    }
    for (int i = k-1; i < n; i++) {
        if (sum[k-1] + of[i].first > b) ans = min(ans, of[i].second+1);
    }
    printf("%d\n", ans);
    return 0;
}
