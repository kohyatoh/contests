#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, len[100];
bool dp[50][1000][1000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", len+i);
    dp[0][0][0]=true;
    int s=0;
    rep(i, n) s+=len[i];
    int m=s/2+1;
    rep(k, n) rep(i, m) rep(j, m) if(dp[k][i][j]) {
        dp[k+1][i][j]=true;
        if(i+len[k]<m) dp[k+1][i+len[k]][j]=true;
        if(j+len[k]<m) dp[k+1][i][j+len[k]]=true;
    }
    int ans=-1;
    double t=s/2.0;
    rep(a, m) rep(b, m) if(dp[n][a][b]) {
        int c=s-a-b;
        if(a>0 && b>0 && c>0 && a+b>c && b+c>a && c+a>b) {
            ans = max(ans, (int)(sqrt(t*(t-a)*(t-b)*(t-c))*100));
        }
    }
    printf("%d\n", ans);
    return 0;
}
