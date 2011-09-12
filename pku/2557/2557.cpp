#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1<<30)
int n, dp[300][300];
char s[300];

int main() {
    while(gets(s)) {
        rep(i, 300) rep(j, 300) dp[i][j]=INF;
        n=strlen(s);
        rep(i, n) dp[i][i]=1;
        for(int w=1; w<n; w++) rep(i, n-w) {
            int j=i+w;
            for(int k=i; k<=j; k++) {
                bool can=true;
                for(int d=1; i<=k-d && k+d<=j; d++) {
                    if(s[k-d]==s[k+d]) {
                        can = false;
                        break;
                    }
                }
                if(!can) continue;
                if(k-i>j-k) dp[i][j]=min(dp[i][j], dp[i][k-1]+1);
                else dp[i][j]=min(dp[i][j], dp[k+1][j]+1);
            }
        }
        printf("%d\n", dp[0][n-1]);
    }
    return 0;
}

