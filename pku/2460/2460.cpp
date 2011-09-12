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

int n, x[200000], y[200000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d %d", x+i, y+i);
        const int cx=x[n/2], cy=y[n/2];
        int c1=0, c2=0;
        rep(i, n) {
            if(x[i]>cx && y[i]>cy) c1++;
            if(x[i]<cx && y[i]<cy) c1++;
            if(x[i]>cx && y[i]<cy) c2++;
            if(x[i]<cx && y[i]>cy) c2++;
        }
        printf("%d %d\n", c1, c2);
    }
}


