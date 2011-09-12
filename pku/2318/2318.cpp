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

int cross(int x1, int y1, int x2, int y2) {
    return (double)x1*y2-(double)x2*y1>0 ? 1 : -1;
}

int xu[6000], xl[6000], c[6000];

int main() {
    for(int q=0;; q++) {
        int n, m, x1, y1, x2, y2;
        scanf("%d", &n);
        if(n==0) return 0;
        memset(c, 0, sizeof(c));
        scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
        rep(i, n) scanf("%d%d", xu+i, xl+i);
        xu[n] = xl[n] = x2;
        n++;
        rep(i, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            int l=-1, r=n-1;
            while(r-l>1) {
                int mid=(l+r)/2;
                if(cross(xu[mid]-xl[mid], y1-y2, x-xl[mid], y-y2)>0) r=mid;
                else l=mid;
            }
            c[r]++;
        }
        if(q) puts("");
        rep(i, n) printf("%d: %d\n", i, c[i]);
    }
}


