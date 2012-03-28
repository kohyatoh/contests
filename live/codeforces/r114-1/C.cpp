#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
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

map<pair<Int, Int>, int> memo;

int win(Int a, Int b) {
    LOG(a);
    LOG(b);
    if (a > b) swap(a, b);
    if (a == 0) return 0;
    if (b % a == 0) return 1;
    if (memo.count(mp(a, b))) return memo[mp(a, b)];
    if (win(b%a, a)) {
        if (win(b-b%a, a)) return memo[mp(a, b)] = 1;
    }
    return memo[mp(a, b)] = !win(b%a, a);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Int a, b;
        cin >> a >> b;
        puts(win(a, b) ? "First" : "Second");
    }
    return 0;
}
