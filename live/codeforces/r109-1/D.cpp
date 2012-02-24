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

pair<int, Int> solve(Int x1, Int x2, Int a, Int b) {
    const Int d = x2 - x1;
    if (a <= d && d <= b) return mp(2, x2);
    if (a <= 0) return mp(0, 0LL);
    if (d < a) return mp(0, 0LL);
    const Int r = (d - b) % (a + b);
    if (1 <= r && r <= a) return mp(1, 0LL);
    if (r == 0) return mp(2, x1+b);
    return mp(2, x1 + max(a, r-a));
}

int main() {
    Int x1, x2, a, b;
    cin >> x1 >> x2 >> a >> b;
    if (x1 < x2) {
        pair<int, Int> ans = solve(x1, x2, a, b);
        if (ans.first == 0) cout << "DRAW" << endl;
        else if (ans.first == 1) cout << "SECOND" << endl;
        else {
            cout << "FIRST" << endl;
            cout << ans.second << endl;
        }
    }
    else {
        pair<int, Int> ans = solve(-x1, -x2, -b, -a);
        if (ans.first == 0) cout << "DRAW" << endl;
        else if (ans.first == 1) cout << "SECOND" << endl;
        else {
            cout << "FIRST" << endl;
            cout << -ans.second << endl;
        }
    }
    return 0;
}

