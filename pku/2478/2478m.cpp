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

int pt[1000001];
Int cnt[1000001], sum[1000001];

int main() {
    for(int i=4; i<1000001; i+=2) pt[i]=2;
    for(int i=3; i<1000; i+=2) if(pt[i]==0) {
        for(int j=i*i; j<1000001; j+=i) pt[j] = i;
    }
    for(int i=2; i<1000001; i++) {
        cnt[i] = i;
        for(int p=i; p>1; ) {
            int b = pt[p] ? pt[p] : p;
            cnt[i] -= cnt[i]/b;
            while(p%b==0) p/=b;
        }
    }
    for(int i=2; i<1000001; i++) sum[i]=sum[i-1]+cnt[i];
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        cout << sum[n] << endl;
    }
}


