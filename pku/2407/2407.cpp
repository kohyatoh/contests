#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
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
#include <functional>
#include <complex>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#else
#define LOG(a) ((void)0)
#define ASS(a) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

int bitcount(int a) {
    int c=0;
    while(a) a&=a-1, c++;
    return c;
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        vector<int> p;
        int t=n;
        for(int i=2, t=n; t>1; i++) if(t%i==0) {
            p.push_back(i);
            while(t%i==0) t/=i;
        }
        const int k=p.size(), kk=1<<k;
        rep(i, k) LOG(p[i]);
        int cnt=0;
        rep(b, kk) if(b) {
            int a=1;
            rep(i, k) if(b&(1<<i)) a*=p[i];
            if(bitcount(b)%2) cnt += (n-1)/a;
            else cnt -= (n-1)/a;
        }
        LOG(cnt);
        printf("%d\n", n-1-cnt);
    }
}


