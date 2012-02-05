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

Int gcd(Int a, Int b) { return b==0 ? a : gcd(b, a%b); }

int N, K, R;
int S[200000], a[200000];

pair<Int, Int> solve() {
    if (K==1) return mp(1LL, 1LL);
    const int F = 150000;
    for (int i = N; i < F+N; i++) {
        S[i] = S[i%N] + N*(i/N);
    }
    map<int, int> cnt;
    int j = 0, t = 0;
    rep (i, F+N) {
        if (cnt[S[i]]++ == 0) t++;
        while (t >= K) {
            if (--cnt[S[j++]] == 0) t--;
        }
        a[i] = j;
    }
    Int ans = 0;
    rep (i, F) if (i <= R) {
        ans += a[i];
    }
    for (int i = F; i < F+N; i++) if (i <= R) {
        const Int m = (R-i)/N;
        ans += (a[i] + a[i] + N*m) * (m+1) / 2;
    }
    return mp(ans*2, (R+1LL)*(R+1LL));
}

int main() {
    int T;
    scanf("%d", &T);
    rep (t, T) {
        scanf("%d%d%d", &N, &K, &R);
        rep (i, N) scanf("%d", S+i);
        const pair<Int, Int> ans = solve();
        const Int g = gcd(ans.first, ans.second);
        cout << "Case #" << t+1 << ": ";
        cout << ans.first/g << "/" << ans.second/g << endl;
    }
    return 0;
}
