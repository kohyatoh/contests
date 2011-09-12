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

int main() {
    int T;
    scanf("%d", &T);
    rep(_t, T) {
        int n, d, b, e;
        scanf("%d%d%d%d", &n, &d, &b, &e);
        printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", _t+1, n, d, b, e);
        int c = n%d;
        rep(i, e+1) {
            c *= 7;
            if(i>=b) putchar('0'+c/d);
            c %= d;
        }
        printf("\n");
    }
    return 0;
}


