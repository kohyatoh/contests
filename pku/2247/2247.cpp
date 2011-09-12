#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, ix[4];
long long dp[6000];
const int f[4] = { 2, 3, 5, 7 };

const char* suf(int n) {
    if(10<=n%100 && n%100<20) return "th";
    if(n%10==1) return "st";
    if(n%10==2) return "nd";
    if(n%10==3) return "rd";
    return "th";
}

int main() {
    dp[k++] = 1;
    while(k<6000) {
        long long mv=1LL<<60;
        rep(i, 4) mv = min(mv, dp[ix[i]]*f[i]);
        dp[k++] = mv;
        rep(i, 4) if(dp[ix[i]]*f[i]==mv) ix[i]++;
    }
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        cout << "The " << n << suf(n) << " humble number is " << dp[n-1] << "." << endl;
    }
}

