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
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

int n, k;
char f[200000];

int main() {
    scanf("%d%d%s", &n, &k, f);
    int cur = 0;
    while(k>0) {
        while(cur<n-1 && !(f[cur]=='4' && f[cur+1]=='7')) cur++;
        LOG(cur);
        if(cur==n-1) break;
        if(cur%2==0) {
            f[cur+1] = '4';
            k--;
        }
        else if(cur>0 && f[cur-1]=='4') {
            if(k%2) f[cur] = '7';
            k = 0;
        }
        else {
            f[cur] = '7';
            k--;
        }
    }
    puts(f);
    return 0;
}


