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

pair<int, int> v[30000];

int main() {
    int n, T;
    scanf("%d%d", &n, &T);
    rep(i, n) scanf("%d%d", &v[i].first, &v[i].second);
    sort(v, v+n);
    int ans=0;
    int i=0, cur=0;
    while(i<n && cur<T) {
        int nxt=-1;
        while(i<n && v[i].first<=cur+1) {
            nxt = max(nxt, v[i].second);
            i++;
        }
        if(nxt==-1) {
            ans = -1;
            break;
        }
        cur = nxt;
        ans++;
    }
    if(cur<T) ans=-1;
    printf("%d\n", ans);
    return 0;
}


