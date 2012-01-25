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

map<char, int> ns;

int solve(string s) {
    map<char, int> cnt;
    rep (i, s.size()) ++cnt[s[i]];
    int ans = INF;
    foreach (it, ns) ans = min(ans, cnt[it->first] / it->second);
    return ans;
}

int main() {
    const string word("HACKERCUP");
    rep (i, word.size()) ++ns[word[i]];
    string s;
    getline(cin, s);
    const int T = atoi(s.c_str());
    rep(t, T) {
        getline(cin, s);
        const int ans = solve(s);
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
