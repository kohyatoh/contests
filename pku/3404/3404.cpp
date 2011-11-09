#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[100], dp[100];

int rec(int k) {
    if(dp[k]!=-1) return dp[k];
    if(k==1) return a[0];
    if(k==2) return a[1];
    return dp[k] = min(a[0]+a[k-1]+rec(k-1), a[0]+a[1]*2+a[k-1]+rec(k-2));
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    sort(a, a+n);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(n));
    return 0;
}
