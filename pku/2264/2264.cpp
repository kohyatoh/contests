#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dp[200][200];
char a[200], b[200], r[500];

int main() {
    while(scanf(" %s%s", a, b)!=EOF) {
        int n=strlen(a), m=strlen(b);
        rep(i, n) rep(j, m) {
            if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
        }
        int k=0, i=n, j=m;
        while(i&&j) {
            if(dp[i][j]==dp[i][j-1]) r[k++]=b[--j];
            else if(dp[i][j]==dp[i-1][j]) r[k++]=a[--i];
            else {
                r[k++]=a[--i];
                j--;
            }
        }
        while(i) r[k++]=a[--i];
        while(j) r[k++]=b[--j];
        reverse(r, r+k);
        r[k] = 0;
        puts(r);
    }
    return 0;
}
