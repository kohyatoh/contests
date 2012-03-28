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
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

int main() {
    int n;
    double a, d;
    scanf("%d%lf%lf", &n, &a, &d);
    double pre = 0;
    rep (_, n) {
        double st, v;
        scanf("%lf%lf", &st, &v);
        double at = v / a;
        double ad = v * at / 2;
        double t = st;
        if (ad > d) t += sqrt(2*d/a);
        else t += at + (d-ad) / v;
        t = max(t, pre);
        printf("%.9f\n", t);
        pre = t;
    }
    return 0;
}
