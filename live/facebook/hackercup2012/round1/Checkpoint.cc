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

map<int, int> of;
int C[1000][1000];

int calc(int S) {
    if (of.count(S) == 0) return S;
    return min(of[S], S);
}

int solve(int S) {
    int ans = INF;
    for (Int i = 1; i*i <= S; i++) if (S%i == 0) {
        ans = min(ans, calc(i)+calc(S/i));
    }
    return ans;
}

int main() {
    C[0][0] = 1;
    rep (i, 999) rep (j, 999) {
        C[i+1][j] = min(C[i+1][j] + C[i][j], INF);
        C[i+1][j+1] = min(C[i+1][j+1] + C[i][j], INF);
    }
    rep (i, 5000) if(i >= 2) of[i*(i-1)/2] = i;
    rep (i, 1000) rep (j, 1000) {
        if (C[i][j] > 1 && C[i][j] < INF) {
            if (of.count(C[i][j]) == 0) of[C[i][j]] = i;
            else of[C[i][j]] = min(of[C[i][j]], i);
        }
    }
    of[1] = 1;
    int T;
    cin >> T;
    rep (t, T) {
        int S;
        cin >> S;
        const int ans = solve(S);
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}

