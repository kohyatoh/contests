#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dp[10000];

int main() {
    for(int q=0; ; q++) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        vector<vector<int> > v;
        rep(i, n) {
            vector<int> w(3);
            rep(j, 3) scanf("%d", &w[j]);
            sort(w.begin(), w.end());
            do v.push_back(w); while(next_permutation(w.begin(), w.end()));
        }
        sort(v.begin(), v.end());
        rep(i, v.size()) {
            dp[i]=v[i][2];
            rep(j, i) if(v[j][0]<v[i][0] && v[j][1]<v[i][1]) {
                dp[i]=max(dp[i], dp[j]+v[i][2]);
            }
        }
        int ans=0;
        rep(i, v.size()) ans=max(ans, dp[i]);
        printf("Case %d: maximum height = %d\n", q+1, ans);
    }
}

