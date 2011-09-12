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

#define INF (1<<28)

int T, n, t, m, c[6000];

int calc(int fst) {
    LOG(fst);
    int capa=0;
    while(fst>=6000) {
        capa+=n;
        fst-=t*2;
    }
    LOG(capa);
    for(int ct=fst; ct>=0; ct--) {
        if((fst-ct)%(t*2)==0) capa += n;
        if(c[ct]!=0) {
            LOG(ct);
            LOG(capa);
        }
        capa -= c[ct];
        if(capa<0) return -1;
    }
    return (m+n-1)/n;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &t, &m);
        memset(c, 0, sizeof(c));
        int mx=0;
        rep(i, m) {
            int a;
            scanf("%d", &a);
            c[a]++;
            mx = max(mx, a);
        }
        int l=mx-1, r=t*3*m;
        while(r-l>1) {
            int mid=(l+r)/2;
            if(calc(mid)==-1) l=mid;
            else r=mid;
        }
        printf("%d %d\n", r+t, calc(r));
    }
    return 0;
}


