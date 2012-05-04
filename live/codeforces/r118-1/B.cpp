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
#define MOD (1000000007LL)

int main() {
    int s, a, b, c;
    cin >> s >> a >> b >> c;
    double w = a + b + c;
    if (w == 0) {
        printf("%.15f %.15f %.15f\n", (double)s, 0.0, 0.0);
    }
    else {
        printf("%.15f %.15f %.15f\n", s*a/w, s*b/w, s*c/w);
    }
    return 0;
}
