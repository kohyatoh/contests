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

#define mw (1000)
inline double sq(double a) { return a*a; }

int n, x[100], y[100];

double calc(double cx, double cy) {
    double ans=0;
    rep(i, n) ans+=sqrt(sq(cx-x[i])+sq(cy-y[i]));
    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", x+i, y+i);
    double cx=(double)accumulate(x, x+n, 0)/n;
    double cy=(double)accumulate(y, y+n, 0)/n;
    double cur=calc(cx, cy);
    double ans=cur;
    rep(w, mw) {
        double dx=(rand()%200-100)/100.0;
        double dy=(rand()%200-100)/100.0;
        double nxt=calc(cx+dx, cy+dy);
        ans = min(ans, nxt);
        if(cur>nxt || rand()%mw>w) cx+=dx,cy+=dy, cur=nxt;
    }
    printf("%.0f\n", ans);
    return 0;
}


