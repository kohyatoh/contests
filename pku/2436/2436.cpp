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
#define DBG(...) (fprintf(stderr,"%d: ",__LINE__)+fprintf(stderr,__VA_ARGS__))
#else
#define LOG(...) ((void)0)
#define ASS(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF MY_INFINITY

int a[1024];

int main() {
    int N, D, K;
    scanf("%d%d%d", &N, &D, &K);
    rep(i, N) {
        int m, d;
        scanf("%d", &m);
        rep(j, m) {
            scanf("%d", &d);
            a[i] |= 1<<(d-1);
        }
    }
    const int dd = 1<<D;
    int ans = 0;
    for(int b=(1<<K)-1; b<dd; ) {
        int c = 0;
        rep(i, N) if((a[i]|b)==b) c++;
        ans = max(ans, c);
        const int x=b&-b, y=b+x;
        b = ((b&~y)/x>>1)|y;
    }
    printf("%d\n", ans);
    return 0;
}


