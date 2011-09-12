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

int T, n;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int ans=INT_MAX;
        for(int h=1; h*h<=n; h++) if(n%h==0) {
            int s=n/h;
            for(int i=1; i*i<=s; i++) if(s%i==0) {
                ans = min(ans, s+s+(i+s/i)*2*h);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


