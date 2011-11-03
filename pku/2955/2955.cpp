#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void cmax(int &a, int b) { if(a<b) a = b; }

char f[128];
int n, dp[128][128];

int main() {
    for(;;) {
        gets(f);
        if(f[0]=='e') return 0;
        n = strlen(f);
        memset(dp, 0, sizeof(dp));
        rep(i, n-1) {
            if(f[i]=='(' && f[i+1]==')') dp[i][i+1] = 2;
            if(f[i]=='[' && f[i+1]==']') dp[i][i+1] = 2;
        }
        for(int w=2; w<n; w++) rep(i, n-w) {
            const int j = i+w;
            cmax(dp[i][j], dp[i+1][j]);
            cmax(dp[i][j], dp[i][j-1]);
            if(f[i]=='(' && f[j]==')') cmax(dp[i][j], dp[i+1][j-1]+2);
            if(f[i]=='[' && f[j]==']') cmax(dp[i][j], dp[i+1][j-1]+2);
            for(int k=i; k<j; k++) cmax(dp[i][j], dp[i][k]+dp[k+1][j]);
        }
        printf("%d\n", dp[0][n-1]);
    }
}
