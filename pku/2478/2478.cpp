#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF MY_INFINITY

Int dp[1000001], sum[1000001];

int main() {
    rep(i, 1000001) dp[i] = i-1;
    for(int i=2; i<=500000; i++) {
        for(int j=i+i; j<1000001; j+=i) dp[j]-=dp[i];
    }
    for(int i=2; i<1000001; i++) sum[i]=sum[i-1]+dp[i];
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        cout << sum[n] << endl;
    }
}


