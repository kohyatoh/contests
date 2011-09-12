#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dp[200000];

int main() {
    for(;;) {
        int n, m;
        cin >> n >> m;
        if(n==0 && m==0) return 0;
        map<string, int> id;
        vector<int> v[16];
        rep(i, n) {
            string s;
            cin >> s;
            id[s] = i;
        }
        rep(i, m) {
            string s;
            int a;
            cin >> a >> s;
            v[id[s]].push_back(a);
        }
        int ans = 0;
        rep(i, n) {
            sort(v[i].begin(), v[i].end());
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            int s = 0;
            rep(j, v[i].size()) {
                const int a = v[i][j];
                for(int k=s; k>=0; k--) dp[k+a] |= dp[k];
                s += a;
            }
            int p = 1<<28;
            rep(j, s+1) if(dp[j]) p = min(p, max(j, s-j));
            ans += p;
        }
        cout << ans << endl;
    }
}
