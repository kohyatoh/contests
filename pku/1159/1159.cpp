#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
char f[6000];
int dp[3][6000];

int main() {
    scanf("%d%s", &n, f);
    rep(i, n-1) dp[1][i] = f[i]!=f[i+1];
    for(int k=2; k<n; k++) {
        const int kx = k%3, k1 = (k+2)%3, k2 = (k+1)%3;
        rep(i, n-k) {
            const int j = i+k;
            dp[kx][i] = min(dp[k1][i], dp[k1][i+1])+1;
            if(f[i]==f[j]) dp[kx][i] = min(dp[kx][i], dp[k2][i+1]);
        }
    }
    printf("%d\n", dp[(n-1)%3][0]);
    return 0;
}
