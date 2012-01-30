#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define MOD (4207849484LL)
typedef long long Int;

Int dp[5000];

Int solve(int m, string s) {
    memset(dp, 0, sizeof(dp));
    dp[s.size()] = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '0') continue;
        int a = 0;
        for (int j = 0; i+j < (int)s.size(); j++) {
            a = a*10 + s[i+j] - '0';
            if (a > m) break;
            dp[i] = (dp[i]+dp[i+j+1]) % MOD;
        }
    }
    return dp[0];
}

int main() {
    int T;
    cin >> T;
    rep (t, T) {
        int M;
        string s;
        cin >> M >> s;
        const Int ans = solve(M, s);
        cout << "Case #" << t+1 << ": " << ans << endl;
    }
    return 0;
}
