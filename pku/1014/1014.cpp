#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[6], dp[200000];

bool solve(int s) {
    if(s%2) return false;
    vector<int> vs;
    rep(i, 6) {
        int r = a[i];
        for(int k=1; k<=r; k*=2) {
            vs.push_back((i+1)*k);
            r -= k;
        }
        if(r>0) vs.push_back((i+1)*r);
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    rep(k, vs.size()) for(int i=s-vs[k]; i>=0; i--) dp[i+vs[k]] |= dp[i];
    return dp[s/2];
}

int main() {
    for(int _q=0;; _q++) {
        rep(i, 6) scanf("%d", a+i);
        int s = 0;
        rep(i, 6) s += a[i]*(i+1);
        if(s==0) return 0;
        printf("Collection #%d:\n", _q+1);
        printf("%s be divided.\n", solve(s) ? "Can" : "Can't");
        printf("\n");
    }
}
