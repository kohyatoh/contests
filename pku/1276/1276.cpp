#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int s, n, m[16], d[16];
int dp[200000];

int main() {
    while(scanf("%d", &s)!=EOF) {
        scanf("%d", &n);
        rep(i, n) scanf("%d%d", m+i, d+i);
        vector<int> v;
        rep(i, n) {
            int x=1, r=m[i];
            while(r>0) {
                v.push_back(min(x, r)*d[i]);
                r -= min(x, r);
                x *= 2;
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        rep(k, v.size()) for(int i=s-v[k]; i>=0; i--) dp[i+v[k]] |= dp[i];
        int ans = 0;
        rep(i, s+1) if(dp[i]) ans = i;
        printf("%d\n", ans);
    }
    return 0;
}
